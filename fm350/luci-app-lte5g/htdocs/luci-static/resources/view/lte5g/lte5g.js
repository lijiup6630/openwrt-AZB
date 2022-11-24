'use strict';
'require view';
'require dom';
'require poll';
'require rpc';
'require uci';
'require form';
'require network';
'require validation';
'require fs';

return view.extend({
    render: function () {
        var  m, s, o;
        m = new form.Map('lte5g', _('LTE5G'));
        s = m.section(form.TypedSection, 'lte5g');
        s.anonymous = true;
        s.addremove = false;
        s.tab('link', _('Link Status'));
        s.tab('Model', _('Model Status'));
        
        s.taboption('link', form.Value, 'imei', _('IMEI'), _(''));
        s.taboption('link', form.Value, 'imsi', _('IMSI'), _(''));
        s.taboption('link', form.Value, 'isp', _('ISP'), _(''));
        s.taboption('link', form.Value, 'number', _('TEL NUMBER'), _(''));
        s.taboption('link', form.Value, 'type', _('TYPE'), _(''));
        s.taboption('link', form.Value, 'freq', _('FREQ'), _(''));
        s.taboption('link', form.Value, 'rsrp', _('RSRP'), _(''));
        s.taboption('link', form.Value, 'rsrq', _('RSRQ'), _(''));

        s.taboption('Model', form.Value, 'bridge_type', _('Bridge Type'));
        s.taboption('Model', form.Value, 'autoconnect', _('Auto Connect'));
        s.taboption('Model', form.Value, 'connect', _('Connect'));
        s.taboption('Model', form.Value, 'apn', _('APN'));

        return m.render();
    }
});