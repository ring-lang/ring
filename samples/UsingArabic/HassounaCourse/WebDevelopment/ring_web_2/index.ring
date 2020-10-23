#!ring -cgi
load "weblib.ring"
import system.web

new page{
html('
<input id="txt" style="font-size:25px">
<button id="btn" style="font-size:25px">
Click Here
</button>
<h3 id="lbl">...</h3>
<script>
$(document).ready(function(){
	$("#btn").click(function(){
		$("#lbl").text( "Hello " + $("#txt").val() )
	});
});
</script>
')
}
