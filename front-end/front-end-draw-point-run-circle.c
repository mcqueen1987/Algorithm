/*

前端线上笔试题--页面中的一个元素（10px*10px）围绕坐标(200, 300) 做圆周运动

题目：
请让页面中的一个元素（10px*10px）围绕坐标(200, 300) 做圆周运动；
 
原理：
1.页面上画一个圆，画一个圆心。在这个圆的圆周上面画一个点，我们就让这个点绕着圆周跑；
2.怎么让这个点跑起来呢？
   我们用javascrip的setInterval(function(),time);这个方法；
       The setInterval() method calls a function or evaluates an expression at specified intervals (in milliseconds).
       setInterval(function(),time)的意思是在time的时间间隔执行函数function()；
       来个栗子：
       setInterval(function(){alert("Hello")}, 3000);  //Alert "Hello" every 3 seconds (3000 milliseconds):
3.有了这个方法就好办了，我们可以每隔一段时间执行一个function，这个function负责让这个点跑起来；
4.其余不解释，看代码；

*/

<html>
<head>
<style type="text/css">
    .item{ 
        width:20px; 
        height:20px;
        border-radius:10px;
        background: blue;
        position: absolute;
    }/*border-radius圆角半径*/
    #point{ 
        left:95px; 
        top:295px;
    }
    #centre{ 
        left:195px; 
        top:295px;
    }
    .circle{ 
        width:200px; 
        height:200px; 
        border:1px red solid; 
        border-radius:100px; 
        position: absolute; 
        top:200px; 
        left:100px;
    }
</style>
</head>

<body>
    <div id="point" class="item"><big>&nbsp&nbsp&nbspRUN!Lamborghini</big></div>
    <div id="centre" class="item"></div>
    <div class="circle"></div>
</body>

<script type="text/javascript">
    var r = 100; //半径
    var a = 0;   //角度
    var obj = document.getElementById('point');//js必须写在<body>后面，否则obj=null；
    // 基点坐标为200,300
    setInterval(function(){
        obj.style.left = (190 - Math.cos(a) * r) + 'px';/*style 很重要*/
        obj.style.top = (290 - Math.sin(a) * r) + 'px';
        a += 0.1; //角度随时增大，产生绕圈的效果
    }, 50);//every 50/1000s run function() one time;
</script>

</html>