local mylib = require("abc")  --对应于test.c中的包名      
 
local function print_events(aoi_events)
    for event_type, info in pairs(aoi_events) do
        print("evt_type", event_type)
        for mobj_id, wobjids in pairs(info) do
            print("mark_obj,v", mobj_id, wobjids)
            for idx, id in ipairs(wobjids) do
                print("wobj", idx, id)
            end
        end
    end
end


local function new_print_events(aoi_events)
    for watcher_id, info in pairs(aoi_events) do
        print("watcher_id", watcher_id)
        for e, info2 in pairs(info) do

            print("event char",e)
            for maker_id, event in ipairs(info2) do
                print("maker_id", maker_id, event)
            end
        end
    end
end


-- print(mylib.add(1.0,2.0))
-- print(mylib.sub(20.1,19))
-- local ret = mylib.get()

-- print_events(ret)

-- local ret = mylib.hello()

local ret, ret2 = mylib.wtf()
print(type(ret))
print(type(ret2))
for k, v in pairs(ret) do
    print("key is", k)
    print("v is", v)
    for kk,vv in pairs(v) do
        print("kk",kk)
        print("vv",vv)
    end
end
