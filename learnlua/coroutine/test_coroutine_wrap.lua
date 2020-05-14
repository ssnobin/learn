local wrap = coroutine.wrap(
    function(input)
        print("input : " .. input)
        local param1, param2 = coroutine.yield("yield")
        print("param1 is : " .. param1)
        print("param2 is : " .. param2)
        --print(a.a) traceback 
        return "return"
    end) 
print(wrap("function input"))
print("this is main chunk")
print(wrap("param1", "param2"))
