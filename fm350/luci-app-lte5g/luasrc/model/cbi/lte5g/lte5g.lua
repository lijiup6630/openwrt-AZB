-- Copyright 2008 Steven Barth <steven@midlink.org>
-- Licensed to the public under the Apache License 2.0.

local wa = require "luci.tools.webadmin"
local fs = require "nixio.fs"

m = Map("lte_5g", nil, nil)

s = m:section(TypedSection, "model", nil)
s.addremove = true
s.anonymous = false


s:option(Flag, "bridge_type", translate("bridge type"))
s:option(Flag, "auto_connect", translate("auto connect"))
s:option(Flag, "connect_status", translate("connect status"))
dl = s:option(Value, "apn_name", translate("apn name"))
dl = s:option(Value, "pdp_type", translate("pdp type"))


local apply = luci.http.formvalue("cbi.apply")
if apply then
       luci.sys.exec("touch /tmp/456")
end   

return m
