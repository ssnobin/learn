local co = coroutine.create(
    function()
        print("error test")
        coroutine.yield(a.a)
    end)
print(coroutine.resume(co))
print(coroutine.status(co))
