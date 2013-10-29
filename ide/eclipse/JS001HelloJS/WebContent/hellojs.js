function hello(a,b,c){
	alert("Hello JS a="+a+",b="+b+",c="+c);
}

//function hello(){
//	console.log(arguments);
//	
////	alert("Fuck");
//}
//
//hello(1,2,3,"aa");


function trace(msg){
	if(window.console){
		window.console.log(msg);
	}
}

var a = 10;

for ( var i = 0; i < 100; i++) {
	
}

trace("Hello");


function A(_name){
	
	this.name = _name;
	
	this.sayHi = function(){
		console.log("Hello "+this.name);
	};
}

var a = new A();
a.sayHi();

function B(_name){
	A.call(this,_name);
	
	this.sayHi = function(){
		console.log("Hello B "+this.name);
	};
}
B.prototype = new A();

var b= new B("ZhangSan");
b.sayHi();

