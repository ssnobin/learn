local co = coroutine.create(
    function()
        print("in coroutine")
        return "coroutine return"
    end)
print(co)
print(type(co))
print(coroutine.status(co))

print(coroutine.resume(co))
