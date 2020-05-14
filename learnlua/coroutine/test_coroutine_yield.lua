local co = coroutine.create(
    function ()
        coroutine.yield("abc", "def")
    end)
print(coroutine.resume(co))
