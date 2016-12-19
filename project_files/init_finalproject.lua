wifi.setmode(wifi.STATION)
wifi.sta.config("HTMAA_Yuval","fablab123")
print(wifi.sta.getip())
NumUses=0
if srv~=nil then
  srv:close()
end
led1 = 7
externalGo = 0
gnd_led = 6
vcc_led = 5
gpio.mode(led1, gpio.OUTPUT)
gpio.mode(externalGo, gpio.OUTPUT)
gpio.mode(gnd_led, gpio.OUTPUT)
gpio.mode(vcc_led, gpio.OUTPUT)
gpio.write(externalGo, gpio.LOW)
gpio.write(gnd_led, gpio.LOW)
gpio.write(vcc_led, gpio.LOW)
srv=net.createServer(net.TCP)
srv:listen(80,function(conn)
    conn:on("receive", function(client,request)
        local buf = "";
        local _, _, method, path, vars = string.find(request, "([A-Z]+) (.+)?(.+) HTTP");
        if(method == nil)then
            _, _, method, path = string.find(request, "([A-Z]+) (.+) HTTP");
        end
        local _GET = {}
        if (vars ~= nil)then
            for k, v in string.gmatch(vars, "(%w+)=(%w+)&*") do
                _GET[k] = v
            end
        end
        buf = buf.."<h1> eToiler ePaper eDispenser</h1>";
        buf = buf.."<p>My IP is ";
        buf = buf..tostring(wifi.sta.getip());
        buf = buf.."</p>";
        buf = buf.."<p>Number times used since last reset: ";
        buf = buf..tostring(NumUses);
        buf = buf.."</p>"
        buf = buf.."<p> Get more on <a href=\"https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=Toilet+Paper\">Amazon</a>&nbsp;</p>";
        buf = buf.."<p>Light: <a href=\"?pin=ON1\"><button>ON</button></a>&nbsp;<a href=\"?pin=OFF1\"><button>OFF</button></a></p>";
        buf = buf.."<p>Dispense: <a href=\"?pin=GO1\"><button>GO</button></a>&nbsp;</p>";
        local _on,_off = "",""
        if(_GET.pin == "ON1")then
              gpio.write(led1, gpio.HIGH);
              gpio.write(vcc_led, gpio.HIGH);
        elseif(_GET.pin == "OFF1")then
              gpio.write(led1, gpio.LOW);
              gpio.write(vcc_led, gpio.LOW);
        elseif(_GET.pin == "GO1")then
              gpio.write(led1, gpio.HIGH);
              gpio.write(externalGo, gpio.HIGH);
              tmr.delay(2000000);
              gpio.write(led1, gpio.LOW);
              gpio.write(externalGo, gpio.LOW);
        end
        client:send(buf);
        client:close();
        collectgarbage();
    end)
end)

