require "AudioEngine" 

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    print("----------------------------------------")
end

local function main()
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)

    local cclog = function(...)
        print(string.format(...))
    end

    ---------------

    local visibleSize = CCDirector:sharedDirector():getVisibleSize()
    local origin = CCDirector:sharedDirector():getVisibleOrigin()

    -- create farm
    local function HelloWorld()
        local layerFarm = CCLayer:create()
        
        print("Hello Cocos2d-x")
        
        local dog = CCSprite:create("dog.png")
        dog:setPosition(200,200)
        layerFarm:addChild(dog)

        -- handing touch events
        local touchBeginPoint = nil

        local function onTouchBegan(x, y)
            return true
        end

        local function onTouchMoved(x, y)
        end

        local function onTouchEnded(x, y)
        end

        local function onTouch(eventType, x, y)
            if eventType == "began" then   
                return onTouchBegan(x, y)
            elseif eventType == "moved" then
                return onTouchMoved(x, y)
            else
                return onTouchEnded(x, y)
            end
        end

        layerFarm:registerScriptTouchHandler(onTouch)
        layerFarm:setTouchEnabled(true)

        return layerFarm
    end


    -- run
    local sceneGame = CCScene:create()
    sceneGame:addChild(HelloWorld())
    CCDirector:sharedDirector():runWithScene(sceneGame)
end


xpcall(main, __G__TRACKBACK__)


