t = {1,3,5,7,9}
for i, val in ipairs(t) do
    print("idx:", i, ",val:", val)
    if i%2==0 then
        table.remove(t,i)
    end
end
print("result")
for i, val in ipairs(t) do
    print("idx:", i, ",val:", val)
end
