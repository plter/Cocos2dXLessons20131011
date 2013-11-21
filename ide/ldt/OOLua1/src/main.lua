--for var=2, 10 do
--	print(var)
--end


function People(name)
	local self = {}
	self.name = name
	
	self.sayHello= function(self)
		print("Hello "..self.name)
	end
	
	return self
end

local p = People("ZhangSan")
p:sayHello()


function Man(name)

	local self = People(name)
	
	self.sayHi = function ()
		print("Man sayHi")
	end
	return self
end

m = Man("Lisi")
m:sayHello()
m:sayHi()