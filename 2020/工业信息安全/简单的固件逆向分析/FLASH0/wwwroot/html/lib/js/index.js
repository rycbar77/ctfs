// Editor: Jean-Marie Stawikowski - HUB/WEB - 22/12/2003
// Copyright © 2004 Schneider Electric, All Rights Reserved.

function index()
{
    indexLanguage('');
}

function indexLanguage(url)
{
	if(isPocketPC())
	{
    window.location.replace(url + 'header.htm');
  }
	else
	{
		otherPlatforms(url);
	}
  document.title=config.titleHtml;
}

function otherPlatforms(url)
{
  document.write(
  '<frameset rows="78,*" cols="*" frameborder="no" border="0" framespacing="0">' +
  '<frame name="header" id="header" src="' + url + 'header.htm" scrolling="no" noresize marginwidth="0" frameborder="no" />' +
  '<frame name="mainTop" id="mainTop" src="' + url + 'home/index.htm" scrolling="auto" noresize marginwidth="0" frameborder="no" />' +
  '<noframes><body><p>This page uses frames, but your browser does not support them.</p></body></noframes>' +
  '</frameset>');
}
