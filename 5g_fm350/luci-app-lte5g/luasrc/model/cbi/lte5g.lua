require("luci.sys")

local m, s
m = Map("lte5g", "LTE/5G Information", "")
s = m:section(TypedSection, "lte5g_section", "")
o=s:option(Value, "imei", "IMEI", "") 
o=s:option(Value, "sn", "SN", "")
o=s:option(Value, "cgmr", "CGMR", "")

o=s:option(Value,"ipaddr", "基站下发IP")
o.datatype="ip4addr"
o=s:option(Value, "apn", "apn", "")

s = m:section(TypedSection, "model_section", "")
o=s:option(Flag, "bridge", "桥接模式", "") 
o=s:option(Flag, "autoconn", "自动拨号", "") 
o=s:option(Flag, "status", "拨号状态", "") 

button = s:option(Button, "_refresh", "刷新")
function button.write(self, section, value)
    luci.sys.exec("/usr/sbin/fm350-tools status")
end

button = s:option(Button, "_connect", "拨号")
function button.write(self, section, value)
    luci.sys.exec("/usr/sbin/fm350-tools connect") 
end

button = s:option(Button, "_setwan", "WAN")
function button.write(self, section, value)
    luci.sys.exec("/usr/sbin/fm350-tools aswan") 
end

-- m:section(SimpleSection).template="lte5g"

-- local apply = luci.http.formvalue("cbi.apply")
-- if apply then
--    luci.sys.exec("/usr/sbin/fm350-tools connect")    
--end 

return m