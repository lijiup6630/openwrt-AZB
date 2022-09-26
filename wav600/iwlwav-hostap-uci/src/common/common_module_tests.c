/*
 * common module tests
 * Copyright (c) 2014-2015, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#include "utils/includes.h"

#include "utils/common.h"
#include "utils/module_tests.h"
#include "crypto/crypto.h"
#include "ieee802_11_common.h"
#include "ieee802_11_defs.h"
#include "gas.h"
#include "wpa_common.h"
#include "sae.h"


struct ieee802_11_parse_test_data {
	u8 *data;
	size_t len;
	ParseRes result;
	int count;
};

static const struct ieee802_11_parse_test_data parse_tests[] = {
	{ (u8 *) "", 0, ParseOK, 0 },
	{ (u8 *) " ", 1, ParseFailed, 0 },
	{ (u8 *) "\xff\x00", 2, ParseUnknown, 1 },
	{ (u8 *) "\xff\x01", 2, ParseFailed, 0 },
	{ (u8 *) "\xdd\x03\x01\x02\x03", 5, ParseUnknown, 1 },
	{ (u8 *) "\xdd\x04\x01\x02\x03\x04", 6, ParseUnknown, 1 },
	{ (u8 *) "\xdd\x04\x00\x50\xf2\x02", 6, ParseUnknown, 1 },
	{ (u8 *) "\xdd\x05\x00\x50\xf2\x02\x02", 7, ParseOK, 1 },
	{ (u8 *) "\xdd\x05\x00\x50\xf2\x02\xff", 7, ParseUnknown, 1 },
	{ (u8 *) "\xdd\x04\x00\x50\xf2\xff", 6, ParseUnknown, 1 },
	{ (u8 *) "\xdd\x04\x50\x6f\x9a\xff", 6, ParseUnknown, 1 },
	{ (u8 *) "\xdd\x04\x00\x90\x4c\x33", 6, ParseOK, 1 },
	{ (u8 *) "\xdd\x04\x00\x90\x4c\xff\xdd\x04\x00\x90\x4c\x33", 12,
	  ParseUnknown, 2 },
	{ (u8 *) "\x10\x01\x00\x21\x00", 5, ParseOK, 2 },
	{ (u8 *) "\x24\x00", 2, ParseOK, 1 },
	{ (u8 *) "\x38\x00", 2, ParseOK, 1 },
	{ (u8 *) "\x54\x00", 2, ParseOK, 1 },
	{ (u8 *) "\x5a\x00", 2, ParseOK, 1 },
	{ (u8 *) "\x65\x00", 2, ParseOK, 1 },
	{ (u8 *) "\x65\x12\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x10\x11",
	  20, ParseOK, 1 },
	{ (u8 *) "\x6e\x00", 2, ParseOK, 1 },
	{ (u8 *) "\xc7\x00", 2, ParseOK, 1 },
	{ (u8 *) "\xc7\x01\x00", 3, ParseOK, 1 },
	{ (u8 *) "\x03\x00\x2a\x00\x36\x00\x37\x00\x38\x00\x2d\x00\x3d\x00\xbf\x00\xc0\x00",
	  18, ParseOK, 9 },
	{ (u8 *) "\x8b\x00", 2, ParseOK, 1 },
	{ (u8 *) "\xdd\x04\x00\x90\x4c\x04", 6, ParseUnknown, 1 },
	{ (u8 *) "\xed\x00", 2, ParseOK, 1 },
	{ (u8 *) "\xef\x00", 2, ParseOK, 1 },
	{ (u8 *) "\xef\x01\x11", 3, ParseOK, 1 },
	{ (u8 *) "\xf0\x00", 2, ParseOK, 1 },
	{ (u8 *) "\xf1\x00", 2, ParseOK, 1 },
	{ (u8 *) "\xf1\x02\x11\x22", 4, ParseOK, 1 },
	{ (u8 *) "\xf2\x00", 2, ParseOK, 1 },
	{ (u8 *) "\xff\x00", 2, ParseUnknown, 1 },
	{ (u8 *) "\xff\x01\x00", 3, ParseUnknown, 1 },
	{ (u8 *) "\xff\x01\x01", 3, ParseOK, 1 },
	{ (u8 *) "\xff\x02\x01\x00", 4, ParseOK, 1 },
	{ (u8 *) "\xff\x01\x02", 3, ParseOK, 1 },
	{ (u8 *) "\xff\x04\x02\x11\x22\x33", 6, ParseOK, 1 },
	{ (u8 *) "\xff\x01\x04", 3, ParseOK, 1 },
	{ (u8 *) "\xff\x01\x05", 3, ParseOK, 1 },
	{ (u8 *) "\xff\x0d\x05\x11\x22\x33\x44\x55\x55\x11\x22\x33\x44\x55\x55",
	  15, ParseOK, 1 },
	{ (u8 *) "\xff\x01\x06", 3, ParseOK, 1 },
	{ (u8 *) "\xff\x02\x06\x00", 4, ParseOK, 1 },
	{ (u8 *) "\xff\x01\x07", 3, ParseOK, 1 },
	{ (u8 *) "\xff\x09\x07\x11\x22\x33\x44\x55\x66\x77\x88", 11,
	  ParseOK, 1 },
	{ (u8 *) "\xff\x01\x0c", 3, ParseOK, 1 },
	{ (u8 *) "\xff\x02\x0c\x00", 4, ParseOK, 1 },
	{ (u8 *) "\xff\x01\x0d", 3, ParseOK, 1 },
	{ NULL, 0, ParseOK, 0 }
};

static int ieee802_11_parse_tests(void)
{
	int i, ret = 0;
	struct wpabuf *buf;

	wpa_printf(MSG_INFO, "ieee802_11_parse tests");

	for (i = 0; parse_tests[i].data; i++) {
		const struct ieee802_11_parse_test_data *test;
		struct ieee802_11_elems elems;
		ParseRes res;

		test = &parse_tests[i];
		res = ieee802_11_parse_elems(test->data, test->len, &elems, 1);
		if (res != test->result ||
		    ieee802_11_ie_count(test->data, test->len) != test->count) {
			wpa_printf(MSG_ERROR, "ieee802_11_parse test %d failed",
				   i);
			ret = -1;
		}
	}

	if (ieee802_11_vendor_ie_concat((const u8 *) "\x00\x01", 2, 0) != NULL)
	{
		wpa_printf(MSG_ERROR,
			   "ieee802_11_vendor_ie_concat test failed");
		ret = -1;
	}

	buf = ieee802_11_vendor_ie_concat((const u8 *) "\xdd\x05\x11\x22\x33\x44\x01\xdd\x05\x11\x22\x33\x44\x02\x00\x01",
					  16, 0x11223344);
	do {
		const u8 *pos;

		if (!buf) {
			wpa_printf(MSG_ERROR,
				   "ieee802_11_vendor_ie_concat test 2 failed");
			ret = -1;
			break;
		}

		if (wpabuf_len(buf) != 2) {
			wpa_printf(MSG_ERROR,
				   "ieee802_11_vendor_ie_concat test 3 failed");
			ret = -1;
			break;
		}

		pos = wpabuf_head(buf);
		if (pos[0] != 0x01 || pos[1] != 0x02) {
			wpa_printf(MSG_ERROR,
				   "ieee802_11_vendor_ie_concat test 3 failed");
			ret = -1;
			break;
		}
	} while (0);
	wpabuf_free(buf);

	return ret;
}


struct rsn_ie_parse_test_data {
	u8 *data;
	size_t len;
	int result;
};

static const struct rsn_ie_parse_test_data rsn_parse_tests[] = {
	{ (u8 *) "", 0, -1 },
	{ (u8 *) "\x30\x00", 2, -1 },
	{ (u8 *) "\x30\x02\x01\x00", 4, 0 },
	{ (u8 *) "\x30\x02\x00\x00", 4, -2 },
	{ (u8 *) "\x30\x02\x02\x00", 4, -2 },
	{ (u8 *) "\x30\x02\x00\x01", 4, -2 },
	{ (u8 *) "\x30\x02\x00\x00\x00", 5, -2 },
	{ (u8 *) "\x30\x03\x01\x00\x00", 5, -3 },
	{ (u8 *) "\x30\x06\x01\x00\x00\x00\x00\x00", 8, -1 },
	{ (u8 *) "\x30\x06\x01\x00\x00\x0f\xac\x04", 8, 0 },
	{ (u8 *) "\x30\x07\x01\x00\x00\x0f\xac\x04\x00", 9, -5 },
	{ (u8 *) "\x30\x08\x01\x00\x00\x0f\xac\x04\x00\x00", 10, -4 },
	{ (u8 *) "\x30\x08\x01\x00\x00\x0f\xac\x04\x00\x01", 10, -4 },
	{ (u8 *) "\x30\x0c\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04",
	  14, 0 },
	{ (u8 *) "\x30\x0c\x01\x00\x00\x0f\xac\x04\x00\x01\x00\x0f\xac\x04",
	  14, -4 },
	{ (u8 *) "\x30\x0c\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x06",
	  14, -1 },
	{ (u8 *) "\x30\x10\x01\x00\x00\x0f\xac\x04\x02\x00\x00\x0f\xac\x04\x00\x0f\xac\x08",
	  18, 0 },
	{ (u8 *) "\x30\x0d\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04\x00",
	  15, -7 },
	{ (u8 *) "\x30\x0e\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04\x00\x00",
	  16, -6 },
	{ (u8 *) "\x30\x0e\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04\x00\x01",
	  16, -6 },
	{ (u8 *) "\x30\x12\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x01",
	  20, 0 },
	{ (u8 *) "\x30\x16\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04\x02\x00\x00\x0f\xac\x01\x00\x0f\xac\x02",
	  24, 0 },
	{ (u8 *) "\x30\x13\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x01\x00",
	  21, 0 },
	{ (u8 *) "\x30\x14\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x01\x00\x00",
	  22, 0 },
	{ (u8 *) "\x30\x16\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x01\x00\x00\x00\x00",
	  24, 0 },
	{ (u8 *) "\x30\x16\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x01\x00\x00\x00\x01",
	  24, -9 },
	{ (u8 *) "\x30\x1a\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x01\x00\x00\x00\x00\x00\x00\x00\x00",
	  28, -10 },
	{ (u8 *) "\x30\x1a\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x01\x00\x00\x00\x00\x00\x0f\xac\x06",
	  28, 0 },
	{ (u8 *) "\x30\x1c\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x04\x01\x00\x00\x0f\xac\x01\x00\x00\x00\x00\x00\x0f\xac\x06\x01\x02",
	  30, 0 },
	{ NULL, 0, 0 }
};

static int rsn_ie_parse_tests(void)
{
	int i, ret = 0;

	wpa_printf(MSG_INFO, "rsn_ie_parse tests");

	for (i = 0; rsn_parse_tests[i].data; i++) {
		const struct rsn_ie_parse_test_data *test;
		struct wpa_ie_data data;

		test = &rsn_parse_tests[i];
		if (wpa_parse_wpa_ie_rsn(test->data, test->len, &data) !=
		    test->result) {
			wpa_printf(MSG_ERROR, "rsn_ie_parse test %d failed", i);
			ret = -1;
		}
	}

	return ret;
}


static int gas_tests(void)
{
	struct wpabuf *buf;

	wpa_printf(MSG_INFO, "gas tests");
	gas_anqp_set_len(NULL);

	buf = wpabuf_alloc(1);
	if (buf == NULL)
		return -1;
	gas_anqp_set_len(buf);
	wpabuf_free(buf);

	buf = wpabuf_alloc(20);
	if (buf == NULL)
		return -1;
	wpabuf_put_u8(buf, WLAN_ACTION_PUBLIC);
	wpabuf_put_u8(buf, WLAN_PA_GAS_INITIAL_REQ);
	wpabuf_put_u8(buf, 0);
	wpabuf_put_be32(buf, 0);
	wpabuf_put_u8(buf, 0);
	gas_anqp_set_len(buf);
	wpabuf_free(buf);

	return 0;
}


static int sae_tests(void)
{
#ifdef CONFIG_SAE
	struct sae_data sae;
	int ret = -1;
	/* IEEE Std 802.11-2020, Annex J.10 */
	const u8 addr1[ETH_ALEN] = { 0x4d, 0x3f, 0x2f, 0xff, 0xe3, 0x87 };
	const u8 addr2[ETH_ALEN] = { 0xa5, 0xd8, 0xaa, 0x95, 0x8e, 0x3c };
	const char *ssid = "byteme";
	const char *pw = "mekmitasdigoat";
	const char *pwid = "psk4internet";
	const u8 local_rand[] = {
		0x99, 0x24, 0x65, 0xfd, 0x3d, 0xaa, 0x3c, 0x60,
		0xaa, 0x65, 0x65, 0xb7, 0xf6, 0x2a, 0x2a, 0x7f,
		0x2e, 0x12, 0xdd, 0x12, 0xf1, 0x98, 0xfa, 0xf4,
		0xfb, 0xed, 0x89, 0xd7, 0xff, 0x1a, 0xce, 0x94
	};
	const u8 local_mask[] = {
		0x95, 0x07, 0xa9, 0x0f, 0x77, 0x7a, 0x04, 0x4d,
		0x6a, 0x08, 0x30, 0xb9, 0x1e, 0xa3, 0xd5, 0xdd,
		0x70, 0xbe, 0xce, 0x44, 0xe1, 0xac, 0xff, 0xb8,
		0x69, 0x83, 0xb5, 0xe1, 0xbf, 0x9f, 0xb3, 0x22
	};
	const u8 local_commit[] = {
		0x13, 0x00, 0x2e, 0x2c, 0x0f, 0x0d, 0xb5, 0x24,
		0x40, 0xad, 0x14, 0x6d, 0x96, 0x71, 0x14, 0xce,
		0x00, 0x5c, 0xe1, 0xea, 0xb0, 0xaa, 0x2c, 0x2e,
		0x5c, 0x28, 0x71, 0xb7, 0x74, 0xf6, 0xc2, 0x57,
		0x5c, 0x65, 0xd5, 0xad, 0x9e, 0x00, 0x82, 0x97,
		0x07, 0xaa, 0x36, 0xba, 0x8b, 0x85, 0x97, 0x38,
		0xfc, 0x96, 0x1d, 0x08, 0x24, 0x35, 0x05, 0xf4,
		0x7c, 0x03, 0x53, 0x76, 0xd7, 0xac, 0x4b, 0xc8,
		0xd7, 0xb9, 0x50, 0x83, 0xbf, 0x43, 0x82, 0x7d,
		0x0f, 0xc3, 0x1e, 0xd7, 0x78, 0xdd, 0x36, 0x71,
		0xfd, 0x21, 0xa4, 0x6d, 0x10, 0x91, 0xd6, 0x4b,
		0x6f, 0x9a, 0x1e, 0x12, 0x72, 0x62, 0x13, 0x25,
		0xdb, 0xe1
	};
	const u8 peer_commit[] = {
		0x13, 0x00, 0x59, 0x1b, 0x96, 0xf3, 0x39, 0x7f,
		0xb9, 0x45, 0x10, 0x08, 0x48, 0xe7, 0xb5, 0x50,
		0x54, 0x3b, 0x67, 0x20, 0xd8, 0x83, 0x37, 0xee,
		0x93, 0xfc, 0x49, 0xfd, 0x6d, 0xf7, 0xe0, 0x8b,
		0x52, 0x23, 0xe7, 0x1b, 0x9b, 0xb0, 0x48, 0xd3,
		0x87, 0x3f, 0x20, 0x55, 0x69, 0x53, 0xa9, 0x6c,
		0x91, 0x53, 0x6f, 0xd8, 0xee, 0x6c, 0xa9, 0xb4,
		0xa6, 0x8a, 0x14, 0x8b, 0x05, 0x6a, 0x90, 0x9b,
		0xe0, 0x3e, 0x83, 0xae, 0x20, 0x8f, 0x60, 0xf8,
		0xef, 0x55, 0x37, 0x85, 0x80, 0x74, 0xdb, 0x06,
		0x68, 0x70, 0x32, 0x39, 0x98, 0x62, 0x99, 0x9b,
		0x51, 0x1e, 0x0a, 0x15, 0x52, 0xa5, 0xfe, 0xa3,
		0x17, 0xc2
	};
	const u8 kck[] = {
		0x1e, 0x73, 0x3f, 0x6d, 0x9b, 0xd5, 0x32, 0x56,
		0x28, 0x73, 0x04, 0x33, 0x88, 0x31, 0xb0, 0x9a,
		0x39, 0x40, 0x6d, 0x12, 0x10, 0x17, 0x07, 0x3a,
		0x5c, 0x30, 0xdb, 0x36, 0xf3, 0x6c, 0xb8, 0x1a
	};
	const u8 pmk[] = {
		0x4e, 0x4d, 0xfa, 0xb1, 0xa2, 0xdd, 0x8a, 0xc1,
		0xa9, 0x17, 0x90, 0xf9, 0x53, 0xfa, 0xaa, 0x45,
		0x2a, 0xe5, 0xc6, 0x87, 0x3a, 0xb7, 0x5b, 0x63,
		0x60, 0x5b, 0xa6, 0x63, 0xf8, 0xa7, 0xfe, 0x59
	};
	const u8 pmkid[] = {
		0x87, 0x47, 0xa6, 0x00, 0xee, 0xa3, 0xf9, 0xf2,
		0x24, 0x75, 0xdf, 0x58, 0xca, 0x1e, 0x54, 0x98
	};
	struct wpabuf *buf = NULL;
	struct crypto_bignum *mask = NULL;

	os_memset(&sae, 0, sizeof(sae));
	buf = wpabuf_alloc(1000);
	if (!buf ||
	    sae_set_group(&sae, 19) < 0 ||
	    sae_prepare_commit(addr1, addr2, (const u8 *) pw, os_strlen(pw),
			       &sae) < 0)
		goto fail;

	/* Override local values based on SAE test vector */
	crypto_bignum_deinit(sae.tmp->sae_rand, 1);
	sae.tmp->sae_rand = crypto_bignum_init_set(local_rand,
						   sizeof(local_rand));
	mask = crypto_bignum_init_set(local_mask, sizeof(local_mask));
	if (!sae.tmp->sae_rand || !mask)
		goto fail;

	if (crypto_bignum_add(sae.tmp->sae_rand, mask,
			      sae.tmp->own_commit_scalar) < 0 ||
	    crypto_bignum_mod(sae.tmp->own_commit_scalar, sae.tmp->order,
			      sae.tmp->own_commit_scalar) < 0 ||
	    crypto_ec_point_mul(sae.tmp->ec, sae.tmp->pwe_ecc, mask,
				sae.tmp->own_commit_element_ecc) < 0 ||
	    crypto_ec_point_invert(sae.tmp->ec,
				   sae.tmp->own_commit_element_ecc) < 0)
		goto fail;

	/* Check that output matches the test vector */
	if (sae_write_commit(&sae, buf, NULL, NULL) < 0)
		goto fail;
	wpa_hexdump_buf(MSG_DEBUG, "SAE: Commit message", buf);

	if (wpabuf_len(buf) != sizeof(local_commit) ||
	    os_memcmp(wpabuf_head(buf), local_commit,
		      sizeof(local_commit)) != 0) {
		wpa_printf(MSG_ERROR, "SAE: Mismatch in local commit");
		goto fail;
	}

	if (sae_parse_commit(&sae, peer_commit, sizeof(peer_commit), NULL, NULL,
			     NULL, 0) != 0 ||
	    sae_process_commit(&sae) < 0)
		goto fail;

	if (os_memcmp(kck, sae.tmp->kck, SAE_KCK_LEN) != 0) {
		wpa_printf(MSG_ERROR, "SAE: Mismatch in KCK");
		goto fail;
	}

	if (os_memcmp(pmk, sae.pmk, SAE_PMK_LEN) != 0) {
		wpa_printf(MSG_ERROR, "SAE: Mismatch in PMK");
		goto fail;
	}

	if (os_memcmp(pmkid, sae.pmkid, SAE_PMKID_LEN) != 0) {
		wpa_printf(MSG_ERROR, "SAE: Mismatch in PMKID");
		goto fail;
	}

	ret = 0;
fail:
	sae_clear_data(&sae);
	wpabuf_free(buf);
	crypto_bignum_deinit(mask, 1);
	return ret;
#else /* CONFIG_SAE */
	return 0;
#endif /* CONFIG_SAE */
}


static int sae_pk_tests(void)
{
#ifdef CONFIG_SAE_PK
	const char *invalid[] = { "a2bc-de3f-ghim-", "a2bcde3fghim", "", NULL };
	struct {
		const char *pw;
		const u8 *val;
	} valid[] = {
		{ "a2bc-de3f-ghim", (u8 *) "\x06\x82\x21\x93\x65\x31\xd0\xc0" },
		{ "aaaa-aaaa-aaaj", (u8 *) "\x00\x00\x00\x00\x00\x00\x00\x90" },
		{ "7777-7777-777f", (u8 *) "\xff\xff\xff\xff\xff\xff\xfe\x50" },
		{ NULL, NULL }
	};
	int i;
	bool failed;

	for (i = 0; invalid[i]; i++) {
		if (sae_pk_valid_password(invalid[i])) {
			wpa_printf(MSG_ERROR,
				   "SAE-PK: Invalid password '%s' not recognized",
				   invalid[i]);
			return -1;
		}
	}

	failed = false;
	for (i = 0; valid[i].pw; i++) {
		u8 *res;
		size_t res_len;
		char *b32;
		const char *pw = valid[i].pw;
		const u8 *val = valid[i].val;
		size_t pw_len = os_strlen(pw);
		size_t bits = (pw_len - pw_len / 5) * 5;
		size_t bytes = (bits + 7) / 8;

		if (!sae_pk_valid_password(pw)) {
			wpa_printf(MSG_ERROR,
				   "SAE-PK: Valid password '%s' not recognized",
				   pw);
			failed = true;
			continue;
		}

		res = sae_pk_base32_decode(pw, pw_len, &res_len);
		if (!res) {
			wpa_printf(MSG_ERROR,
				   "SAE-PK: Failed to decode password '%s'",
				   valid[i].pw);
			failed = true;
			continue;
		}
		if (res_len != bytes || os_memcmp(val, res, res_len) != 0) {
			wpa_printf(MSG_ERROR,
				   "SAE-PK: Mismatch for decoded password '%s'",
				   valid[i].pw);
			wpa_hexdump(MSG_INFO, "SAE-PK: Decoded value",
				    res, res_len);
			wpa_hexdump(MSG_INFO, "SAE-PK: Expected value",
				    val, bytes);
			failed = true;
		}
		os_free(res);

		b32 = sae_pk_base32_encode(val, bits - 5);
		if (!b32) {
			wpa_printf(MSG_ERROR,
				   "SAE-PK: Failed to encode password '%s'",
				   pw);
			failed = true;
			continue;
		}
		if (os_strcmp(b32, pw) != 0) {
			wpa_printf(MSG_ERROR,
				   "SAE-PK: Mismatch for password '%s'", pw);
			wpa_printf(MSG_INFO, "SAE-PK: Encoded value: '%s'",
				   b32);
			failed = true;
		}
		os_free(b32);
	}

	return failed ? -1 : 0;
#else /* CONFIG_SAE_PK */
	return 0;
#endif /* CONFIG_SAE_PK */
}


#ifdef CONFIG_PASN

static int pasn_test_pasn_auth(void)
{
	/* Test vector taken from IEEE P802.11az/D2.6, J.12 */
	const u8 pmk[] = {
		0xde, 0xf4, 0x3e, 0x55, 0x67, 0xe0, 0x1c, 0xa6,
		0x64, 0x92, 0x65, 0xf1, 0x9a, 0x29, 0x0e, 0xef,
		0xf8, 0xbd, 0x88, 0x8f, 0x6c, 0x1d, 0x9c, 0xc9,
		0xd1, 0x0f, 0x04, 0xbd, 0x37, 0x8f, 0x3c, 0xad
	};

	const u8 spa_addr[] = {
		0x00, 0x90, 0x4c, 0x01, 0xc1, 0x07
	};
	const u8 bssid[] = {
		0xc0, 0xff, 0xd4, 0xa8, 0xdb, 0xc1
	};
	const u8 dhss[] = {
		0xf8, 0x7b, 0x20, 0x8e, 0x7e, 0xd2, 0xb7, 0x37,
		0xaf, 0xdb, 0xc2, 0xe1, 0x3e, 0xae, 0x78, 0xda,
		0x30, 0x01, 0x23, 0xd4, 0xd8, 0x4b, 0xa8, 0xb0,
		0xea, 0xfe, 0x90, 0xc4, 0x8c, 0xdf, 0x1f, 0x93
	};
	const u8 kck[] = {
		0x7b, 0xb8, 0x21, 0xac, 0x0a, 0xa5, 0x90, 0x9d,
		0xd6, 0x54, 0xa5, 0x60, 0x65, 0xad, 0x7c, 0x77,
		0xeb, 0x88, 0x9c, 0xbe, 0x29, 0x05, 0xbb, 0xf0,
		0x5a, 0xbb, 0x1e, 0xea, 0xc8, 0x8b, 0xa3, 0x06
	};
	const u8 tk[] = {
		0x67, 0x3e, 0xab, 0x46, 0xb8, 0x32, 0xd5, 0xa8,
		0x0c, 0xbc, 0x02, 0x43, 0x01, 0x6e, 0x20, 0x7e
	};
	const u8 kdk[] = {
		0x2d, 0x0f, 0x0e, 0x82, 0xc7, 0x0d, 0xd2, 0x6b,
		0x79, 0x06, 0x1a, 0x46, 0x81, 0xe8, 0xdb, 0xb2,
		0xea, 0x83, 0xbe, 0xa3, 0x99, 0x84, 0x4b, 0xd5,
		0x89, 0x4e, 0xb3, 0x20, 0xf6, 0x9d, 0x7d, 0xd6
	};
	struct wpa_ptk ptk;
	int ret;

	ret = pasn_pmk_to_ptk(pmk, sizeof(pmk),
			      spa_addr, bssid,
			      dhss, sizeof(dhss),
			      &ptk, WPA_KEY_MGMT_PASN, WPA_CIPHER_CCMP,
			      WPA_KDK_MAX_LEN);

	if (ret)
		return ret;

	if (ptk.kck_len != sizeof(kck) ||
	    os_memcmp(kck, ptk.kck, sizeof(kck)) != 0) {
		wpa_printf(MSG_ERROR, "PASN: Mismatched KCK");
		return -1;
	}

	if (ptk.tk_len != sizeof(tk) ||
	    os_memcmp(tk, ptk.tk, sizeof(tk)) != 0) {
		wpa_printf(MSG_ERROR, "PASN: Mismatched TK");
		return -1;
	}

	if (ptk.kdk_len != sizeof(kdk) ||
	    os_memcmp(kdk, ptk.kdk, sizeof(kdk)) != 0) {
		wpa_printf(MSG_ERROR, "PASN: Mismatched KDK");
		return -1;
	}

	return 0;
}


static int pasn_test_no_pasn_auth(void)
{
	/* Test vector taken from IEEE P802.11az/D2.6, J.13 */
	const u8 pmk[] = {
		0xde, 0xf4, 0x3e, 0x55, 0x67, 0xe0, 0x1c, 0xa6,
		0x64, 0x92, 0x65, 0xf1, 0x9a, 0x29, 0x0e, 0xef,
		0xf8, 0xbd, 0x88, 0x8f, 0x6c, 0x1d, 0x9c, 0xc9,
		0xd1, 0x0f, 0x04, 0xbd, 0x37, 0x8f, 0x3c, 0xad
	};
	const u8 aa[] = {
		0xc0, 0xff, 0xd4, 0xa8, 0xdb, 0xc1
	};
	const u8 spa[] = {
		0x00, 0x90, 0x4c, 0x01, 0xc1, 0x07
	};
	const u8 anonce[] = {
		0xbe, 0x7a, 0x1c, 0xa2, 0x84, 0x34, 0x7b, 0x5b,
		0xd6, 0x7d, 0xbd, 0x2d, 0xfd, 0xb4, 0xd9, 0x9f,
		0x1a, 0xfa, 0xe0, 0xb8, 0x8b, 0xa1, 0x8e, 0x00,
		0x87, 0x18, 0x41, 0x7e, 0x4b, 0x27, 0xef, 0x5f
	};
	const u8 snonce[] = {
		0x40, 0x4b, 0x01, 0x2f, 0xfb, 0x43, 0xed, 0x0f,
		0xb4, 0x3e, 0xa1, 0xf2, 0x87, 0xc9, 0x1f, 0x25,
		0x06, 0xd2, 0x1b, 0x4a, 0x92, 0xd7, 0x4b, 0x5e,
		0xa5, 0x0c, 0x94, 0x33, 0x50, 0xce, 0x86, 0x71
	};
	const u8 kck[] = {
		0xcd, 0x7b, 0x9e, 0x75, 0x55, 0x36, 0x2d, 0xf0,
		0xb6, 0x35, 0x68, 0x48, 0x4a, 0x81, 0x12, 0xf5
	};
	const u8 kek[] = {
		0x99, 0xca, 0xd3, 0x58, 0x8d, 0xa0, 0xf1, 0xe6,
		0x3f, 0xd1, 0x90, 0x19, 0x10, 0x39, 0xbb, 0x4b
	};
	const u8 tk[] = {
		0x9e, 0x2e, 0x93, 0x77, 0xe7, 0x53, 0x2e, 0x73,
		0x7a, 0x1b, 0xc2, 0x50, 0xfe, 0x19, 0x4a, 0x03
	};
	const u8 kdk[] = {
		0x6c, 0x7f, 0xb9, 0x7c, 0xeb, 0x55, 0xb0, 0x1a,
		0xcf, 0xf0, 0x0f, 0x07, 0x09, 0x42, 0xbd, 0xf5,
		0x29, 0x1f, 0xeb, 0x4b, 0xee, 0x38, 0xe0, 0x36,
		0x5b, 0x25, 0xa2, 0x50, 0xbb, 0x2a, 0xc9, 0xff
	};
	struct wpa_ptk ptk;
	int ret;

	ret = wpa_pmk_to_ptk(pmk, sizeof(pmk),
			     "Pairwise key expansion",
			     spa, aa, snonce, anonce,
			     &ptk, WPA_KEY_MGMT_SAE, WPA_CIPHER_CCMP,
			     NULL, 0, WPA_KDK_MAX_LEN);

	if (ret)
		return ret;

	if (ptk.kck_len != sizeof(kck) ||
	    os_memcmp(kck, ptk.kck, sizeof(kck)) != 0) {
		wpa_printf(MSG_ERROR, "KDK no PASN auth: Mismatched KCK");
		return -1;
	}

	if (ptk.kek_len != sizeof(kek) ||
	    os_memcmp(kek, ptk.kek, sizeof(kek)) != 0) {
		wpa_printf(MSG_ERROR, "KDK no PASN auth: Mismatched KEK");
		return -1;
	}

	if (ptk.tk_len != sizeof(tk) ||
	    os_memcmp(tk, ptk.tk, sizeof(tk)) != 0) {
		wpa_printf(MSG_ERROR, "KDK no PASN auth: Mismatched TK");
		return -1;
	}

	if (ptk.kdk_len != sizeof(kdk) ||
	    os_memcmp(kdk, ptk.kdk, sizeof(kdk)) != 0) {
		wpa_printf(MSG_ERROR, "KDK no PASN auth: Mismatched KDK");
		return -1;
	}

	return 0;
}

#endif /* CONFIG_PASN */


static int pasn_tests(void)
{
#ifdef CONFIG_PASN
	if (pasn_test_pasn_auth() ||
	    pasn_test_no_pasn_auth())
		return -1;
#endif /* CONFIG_PASN */
	return 0;
}


int common_module_tests(void)
{
	int ret = 0;

	wpa_printf(MSG_INFO, "common module tests");

	if (ieee802_11_parse_tests() < 0 ||
	    gas_tests() < 0 ||
	    sae_tests() < 0 ||
	    sae_pk_tests() < 0 ||
	    pasn_tests() < 0 ||
	    rsn_ie_parse_tests() < 0)
		ret = -1;

	return ret;
}
