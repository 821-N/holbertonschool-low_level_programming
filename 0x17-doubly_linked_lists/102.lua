#!/usr/bin/lua5.3

function palindrome(str)
 for i=1,#str/2 do
  if str:sub(i,i) ~= str:sub(#str-i+1,#str-i+1) then return false end
 end
 return true
end

largest=0
for i=1,999 do
 for j=1,999 do
  if i*j>largest and palindrome(tostring(i*j)) then
   largest=i*j
	print(i,j)
  end
 end
end