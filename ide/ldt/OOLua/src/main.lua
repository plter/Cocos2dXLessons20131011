function clone(table)
	local ins = {}
	for key, var in pairs(table) do
		ins[key] = var
	end
	return ins
end

function copy(dist,table)
	for key, var in pairs(table) do
		dist[key] = var
	end
end

-- People >>>>>>>>>>>>>>>>>>>>
People={}
function People.new(name)
	local self = clone(People)
--	self.name = name
	self["name"] = name
	return self
end

--People.new = function ()
--	return clone(People)
--end
People.sayHello = function(self)
	print("People sayHello "..self.name)
end

--<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
--People.name = "ZhangSan"

--People.sayHello()

local p = People.new("ZhangSan")
--p.sayHello()
p:sayHello()


Man = {}
function Man.new(name)
	local self = People.new(name)
	copy(self,Man)
	return self
end

function Man.sayHi()
	print("Man sayHi")
end

--function Man.sayHello()
--	print("Man sayHello")
--end

local m = Man.new("Lisi")
--m:sayHi()
m:sayHello()


