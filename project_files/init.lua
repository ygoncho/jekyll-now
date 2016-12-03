wifi.setmode(wifi.STATION)
wifi.sta.config("MYSSID","MYPASS")
print(wifi.sta.getip())
if srv~=nil then
  srv:close()
end
led1 = 7
gpio.mode(led1, gpio.OUTPUT)
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
        buf = buf.."<p>Light: <a href=\"?pin=ON1\"><button>ON</button></a>&nbsp;<a href=\"?pin=OFF1\"><button>OFF</button></a></p>";
        buf = buf.."<p>Direction: <a href=\"?pin=CW1\"><button>CW</button></a>&nbsp;<a href=\"?pin=CCW1\"><button>CCW</button></a></p>";
        buf = buf.."<p>Dispense: <a href=\"?pin=GO1\"><button>GO</button></a>&nbsp;</p>";
        local _on,_off = "",""
        if(_GET.pin == "ON1")then
              gpio.write(led1, gpio.HIGH);
        elseif(_GET.pin == "OFF1")then
              gpio.write(led1, gpio.LOW);
        end
        client:send(buf);
        client:close();
        collectgarbage();
    end)
end)

