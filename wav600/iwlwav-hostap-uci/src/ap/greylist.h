/*
 * hostapd / RADIUS Greylist Access Control
 * Copyright 2021 MaxLinear
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef GREYLIST_H
#define GREYLIST_H

void greylist_load(struct hapd_interfaces *interfaces);
int greylist_add(struct hapd_interfaces *interfaces, const char *txtaddr,const char *ifname);
int greylist_add_filter_only(const char *txtaddr);
u8 greylist_get_client_snr(struct hostapd_data *hapd, struct sta_info *sta);
int greylist_clear_all(struct hostapd_data *hapd);

#endif /* GREYLIST_H */
