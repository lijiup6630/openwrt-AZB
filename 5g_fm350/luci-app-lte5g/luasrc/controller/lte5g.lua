module("luci.controller.lte5g", package.seeall)
function index()
    entry({"admin", "network", "lte5g"}, cbi("lte5g"), "LTE/5G" , 1)
end