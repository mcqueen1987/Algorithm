/*

阿里校招：前端线上笔试题--计算鼠标在页面某个区域内的停留时长

校招：阿里前端笔试题
收到笔试通知后恶补了几天阿里前端历年笔试题，巧的是这道题今年有同学做过，而且发到了北邮人bbs上（看来临阵磨枪还是有用的），现在贴上当时提交的代码。

水平有限，有错误烦请指点。

题目：
 <div class='mod-spm'data-spmid='123'>
        <divclass='child_a'></div>
        <divclass='child_b'></div>
        <divclass='child_c'></div>
        <divclass='child_d'></div>
    </div>
    <divclass='mod-spm' data-spmid='456'>
        <divclass='child_a'></div>
        <divclass='child_b'></div>
        <divclass='child_c'></div>
        <divclass='child_d'></div>
    </div>
    <divclass='mod-spm' data-spmid='789'>
        <divclass='child_a'></div>
        <divclass='child_b'></div>
        <divclass='child_c'></div>
        <divclass='child_d'></div>
    </div>
有dom结构如上,请用原生代码（禁用jQuery作答）实现以下功能：
(a)计算鼠标在mod-spm区域内的停留时长，data-spm不同视为不同区域
(b)尽量减少性能损耗
(c)重复进入计时累加

思路：

1.在每个块上添加事件：

  onmouseover：鼠标停留该区域，触发计时方法fun()；  

  onmouseout：鼠标离开该区域，触发取消计时的方法funstop()；

2.在方法fun()中使用了HTML5 Web Workers属性，w3school的解释是：

   web worker 是运行在后台的 JavaScript，独立于其他脚本，不会影响页面的性能。

   您可以继续做任何愿意做的事情：点击、选取内容等等，而此时 web worker 在后台运行。

3.我们利用web worker将参数：区域的id传给后台文件worker.js处理计时；

    id=0时，表示计时结束；

    id !=0时，开始开启与此id相应的计时器，开始计时；

4.思路不难，实现的代码如下：
*/

<html>
<head>
</head>
<body>
    <div class='mod-spm' data-spmid='123' onmouseover="fun(this.dataset.spmid)" onmouseout = "funstop()">
        <div class='child_a'></div>
        <div class='child_b'></div>
        <div class='child_c'></div>
        <div class='child_d'></div>
    </div>
    <div class='mod-spm' data-spmid='456' onmouseover="fun(this.dataset.spmid)" onmouseout = "funstop()">
        <div class='child_a'></div>
        <div class='child_b'></div>
        <div class='child_c'></div>
        <div class='child_d'></div>
    </div>
    <div class='mod-spm' data-spmid='789' onmouseover="fun(this.dataset.spmid)" onmouseout = "funstop()">
        <div class='child_a'></div>
        <div class='child_b'></div>
        <div class='child_c'></div>
        <div class='child_d'></div>
    </div>
</body>


<script type="text/javascript">
      var w=new Worker("../workers.js");//使用HTML5 Web Workers属性
      function fun(curid){ //Init
          w.postMessage(curid);//The Worker.postMessage() method sends a message to the worker's inner scope. This accepts a single parameter, which is the data to send to the worker. 
      }
      function funstop(){
          w.postMessage(0);//设置id为0，不计数
      }
</script>

<html>

  //worker.js  后台文件
  var timers = new Array();
  var  i = 0;
  var id = 0;
  function timedCount()
  {
      if(id == 0) return;
      if(timers[id] == undefined){
          timers[id] = 0;
      }
      setTimeout("timedCount()",1000);//每隔一秒累加器+1；
      timers[id] ++;
  }
  onmessage = function(spmid){
    id = spmid.data;  /*the onmessage callback for a Web Worker*/
  }

