// Editor: Jean-Marie Stawikowski - HUB/WEB - 22/12/2003
// Copyright © 2004 Schneider Electric, All Rights Reserved.

var id=0;
var niv=0;
var timeoutId;
   
function Directory(url)
{
  var i1 = url.lastIndexOf('/index.htm');
  var ch = '/';

  if(i1==-1)
  {
    i1 = url.lastIndexOf('\\index.htm');
    ch = '\\';
  }

  var x = url.substring(0, i1);
  return x.substring(x.lastIndexOf(ch)+1, i1);
}



function selectMenu()
{
  window.clearTimeout(timeoutId);

  var mainTop = parent.frames['mainTop'];
  if(mainTop)
  {
    var id = Directory(mainTop.document.URL);
    var header = parent.frames['header'];

    if(header && header.selectMenu)
    {
      header.selectMenu(id);
      return true;
    }
    else
    {
      return false;
    }
  }
}

function framesetLoaded()
{
  if(selectMenu()==false)
  {
    timeoutId = window.setTimeout('selectMenu()', 100);
  }
}

function index(url)
{
	if(isPocketPC())
	{
    window.location.replace('menu.htm');
  }
	else if(url)
	{
		otherPlatformsIndex(url);
	}
	else
	{
		otherPlatformsIndex('../home/home.htm');
	}
  document.title=config.titleHtml;
}

function otherPlatformsIndex(url)
{
document.write(
'<frameset onload="framesetLoaded();" cols="156,*" frameborder="no" border="0" framespacing="0" >' +
'<frame name="panel" id="panel" src="menu.htm" scrolling="auto" noresize marginwidth="0" frameborder="no" />' +
'<frame name="main" id="main" src="' + url + '" scrolling="auto" noresize marginwidth="0" frameborder="no"/>' +
'<noframes><body><p>This page uses frames, but your browser does not support them.</p></body></noframes>' +
'</frameset>');
}

function menu(items)
{
	if(isPocketPC())
	{
    PocketPC(items);
  }
	else
	{
		otherPlatformsMenu(items);
	}
  document.title=config.titleHtml;
}

function PocketPC(items)
{
  document.write('<body>');
  document.write('<img src="../' + config.logoPocketPC + '" >');
  document.write('<div class="productPocketPC">' + config.title + '</div>');
  PocketPCmenu2(items);
  document.write('</body>');
}

function otherPlatformsMenu(items)
{
  document.write('<body>');
  otherPlatformsMenu2(items);
  document.writeln('</body>');
}

function otherPlatformsMenu2(items)
{
  if((typeof items[0]=='string' ))
  {
    var left = 8*niv;
    
    if((typeof items[1]=='string' ))
    {
      var target = ((typeof items[2]=='string')?items[2]:'main');

      if(target=='_top')
      {
        var targetParent = parent.parent.name;
        if(targetParent && targetParent!="mainTop")
        {
          target=targetParent;
        }
      }
      document.write('<a style="padding-left:' + left + ';padding-right:8;cursor:hand;" href="' + items[1] + '" target="' + target + '">' + items[0] + '</a><br/>');
    }
    else
    {
      var close = ((typeof items[1]=='boolean') && (items[1]==false));

      if(niv==0)
      {
        document.write('<div style="padding-left:8;font-weight:bold;height:18px;" >' + items[0] + '</div>');
        document.write('<hr width="100%" size="1" />');
      }
      else
      {
        id++;
        document.write('<a href="javascript:openMenu(' + id + ');" style="padding-left:'+ (left-4) + ';cursor:hand;font-weight:bold;height:18px;" ><img id="Img' + id + '" hspace="4" align="middle" border="0" src="../../lib/images/' + (close?'plus':'moins') + '.gif">' + items[0] + '</a><br/>');
      }

      niv++;
      document.write('<div id="Div' + id  + '"' + (close?' style="display:none"':'') +'>' );

      for(var i=1; i<items.length; i++)
      {
        otherPlatformsMenu2( items[i]);
      }

      document.write('</div>');
      niv--;
    }

    if(niv==1) document.write('<hr width="100%" size="1" />');
  }
}

function PocketPCmenu2(items)
{
  if((typeof items[0]=='string' ))
  {
    if((typeof items[1]=='string' ))
    {
      document.write('<li><a style="color:Black" href="' + items[1] + '">' + items[0] + '</a>');
    }
    else
    {
      if(niv==0)
      {
        document.write('<div class="categoryPocketPC">' + items[0] + '</div>');
      }
      else
      {
        document.write('<li>' + items[0] );
      }

      niv++;
      document.write('<ul>');

      for(var i=1; i<items.length; i++)
      {
        PocketPCmenu2( items[i] );
      }

      document.write('</ul>');
      niv--;
    }
  }
}

function openMenu(id)
{
  var div = document.getElementById('Div' + id);
  var img = document.getElementById('Img' + id);
  
  if (div.style.display == 'none')
  {
    div.style.display = "inline";
    img.src = '../../lib/images/moins.gif';
  }
  else
  {
    div.style.display = 'none';
    img.src = '../../lib/images/plus.gif';
  }
}
