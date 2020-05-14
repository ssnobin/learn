local co
local co2 = coroutine.create(
    function()
        print("3." .. coroutine.status(co))
    end)

co = coroutine.create(
    function()
        print("2." .. coroutine.status(co))
        coroutine.resume(co2)
        print("i wake up?") 
        coroutine.yield()
    end)

print("1." .. coroutine.status(co))
coroutine.resume(co)
print("4." .. coroutine.status(co))
coroutine.resume(co)
print("5." .. coroutine.status(co))
