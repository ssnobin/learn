for k,v in pairs(_G) do
    print(k,v)
end

print "=============================="
--module("test")
local root = debug.getregistry()
for k,v in pairs(root) do
    print(k,v)
end

print "qwer"
