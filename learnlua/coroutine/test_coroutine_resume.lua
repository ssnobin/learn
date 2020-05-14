local co = coroutine.create(
    function(input)
        print("input : " .. input)
        local param1, param2 = coroutine.yield("yield")
        print("param1 is: " .. param1)
        print("param2 is: " .. param2)
        return "return"
    end)

print(coroutine.resume(co, "function input"))
print("this is main chunk")
print(coroutine.resume(co, "param1", "param2"))
