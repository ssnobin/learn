local co = coroutine.create(
    function()
        print(coroutine.running())
    end)
print(coroutine.running())
coroutine.resume(co)
print(co)
