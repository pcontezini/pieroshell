
  
  

  


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
    <meta http-equiv="content-type" content="text/html;charset=UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="chrome=1">
        <title>include/proxylib/debug.h at master from jweyrich's proxylib - GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="http://github.com/fluidicon.png" title="GitHub" />

    <link href="http://assets3.github.com/stylesheets/bundle_common.css?ca4dc080a760e83060a978a6592f45642990f642" media="screen" rel="stylesheet" type="text/css" />
<link href="http://assets3.github.com/stylesheets/bundle_github.css?ca4dc080a760e83060a978a6592f45642990f642" media="screen" rel="stylesheet" type="text/css" />

    <script type="text/javascript" charset="utf-8">
      var GitHub = {}
      var github_user = null
      
    </script>
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.4.2/jquery.min.js" type="text/javascript"></script>
    <script src="http://assets1.github.com/javascripts/bundle_common.js?ca4dc080a760e83060a978a6592f45642990f642" type="text/javascript"></script>
<script src="http://assets2.github.com/javascripts/bundle_github.js?ca4dc080a760e83060a978a6592f45642990f642" type="text/javascript"></script>

        <script type="text/javascript" charset="utf-8">
      GitHub.spy({
        repo: "jweyrich/proxylib"
      })
    </script>

    
  
    
  

  <link href="http://github.com/jweyrich/proxylib/commits/master.atom" rel="alternate" title="Recent Commits to proxylib:master" type="application/atom+xml" />

        <meta name="description" content="A starting project for a fully async C++ proxy library based on Boost Asio." />
    <script type="text/javascript">
      GitHub.nameWithOwner = GitHub.nameWithOwner || "jweyrich/proxylib";
      GitHub.currentRef = "master";
    </script>
  

            <script type="text/javascript">
      var _gaq = _gaq || [];
      _gaq.push(['_setAccount', 'UA-3769691-2']);
      _gaq.push(['_trackPageview']);
      (function() {
        var ga = document.createElement('script');
        ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
        ga.setAttribute('async', 'true');
        document.documentElement.firstChild.appendChild(ga);
      })();
    </script>

  </head>

  

  <body>
    
    

    

    <div class="subnavd" id="main">
      <div id="header" class="pageheaded">
        <div class="site">
          <div class="logo">
            <a href="http://github.com"><img src="/images/modules/header/logov3.png" alt="github" /></a>
          </div>
          
          <div class="topsearch">
  
    <form action="/search" id="top_search_form" method="get">
      <a href="/search" class="advanced-search tooltipped downwards" title="Advanced Search">Advanced Search</a>
      <input type="search" class="search my_repos_autocompleter" name="q" results="5" placeholder="Search&hellip;" /> <input type="submit" value="Search" class="button" />
      <input type="hidden" name="type" value="Everything" />
      <input type="hidden" name="repo" value="" />
      <input type="hidden" name="langOverride" value="" />
      <input type="hidden" name="start_value" value="1" />
    </form>
  
  
    <ul class="nav logged_out">
      
        <li><a href="http://github.com">Home</a></li>
        <li class="pricing"><a href="/plans">Pricing and Signup</a></li>
        <li><a href="http://github.com/explore">Explore GitHub</a></li>
        
        <li><a href="/blog">Blog</a></li>
      
      <li><a href="https://github.com/login">Login</a></li>
    </ul>
  
</div>

        </div>
      </div>

      
      
        
    <div class="site">
      <div class="pagehead repohead vis-public   ">
        <h1>
          <a href="/jweyrich">jweyrich</a> / <strong><a href="http://github.com/jweyrich/proxylib">proxylib</a></strong>
          
          
        </h1>

        
    <ul class="actions">
      

      
        <li class="for-owner" style="display:none"><a href="https://github.com/jweyrich/proxylib/edit" class="minibutton btn-admin "><span><span class="icon"></span>Admin</span></a></li>
        <li>
          <a href="/jweyrich/proxylib/toggle_watch" class="minibutton btn-watch " id="watch_button" style="display:none"><span><span class="icon"></span>Watch</span></a>
          <a href="/jweyrich/proxylib/toggle_watch" class="minibutton btn-watch " id="unwatch_button" style="display:none"><span><span class="icon"></span>Unwatch</span></a>
        </li>
        
          <li class="for-notforked" style="display:none"><a href="/jweyrich/proxylib/fork" class="minibutton btn-fork " id="fork_button" onclick="var f = document.createElement('form'); f.style.display = 'none'; this.parentNode.appendChild(f); f.method = 'POST'; f.action = this.href;var s = document.createElement('input'); s.setAttribute('type', 'hidden'); s.setAttribute('name', 'authenticity_token'); s.setAttribute('value', '16c5370b3adc5564c95b2ce627e618c8efd54445'); f.appendChild(s);f.submit();return false;"><span><span class="icon"></span>Fork</span></a></li>
          <li class="for-hasfork" style="display:none"><a href="#" class="minibutton btn-fork " id="your_fork_button"><span><span class="icon"></span>Your Fork</span></a></li>
          <li id="pull_request_item" style="display:none"><a href="/jweyrich/proxylib/pull_request/" class="minibutton btn-pull-request "><span><span class="icon"></span>Pull Request</span></a></li>
          <li><a href="#" class="minibutton btn-download " id="download_button"><span><span class="icon"></span>Download Source</span></a></li>
        
      
      <li class="repostats">
        <ul class="repo-stats">
          <li class="watchers"><a href="/jweyrich/proxylib/watchers" title="Watchers" class="tooltipped downwards">1</a></li>
          <li class="forks"><a href="/jweyrich/proxylib/network" title="Forks" class="tooltipped downwards">1</a></li>
        </ul>
      </li>
    </ul>


        <ul class="tabs">
  <li><a href="http://github.com/jweyrich/proxylib/tree/master" class="selected" highlight="repo_source">Source</a></li>
  <li><a href="http://github.com/jweyrich/proxylib/commits/master" highlight="repo_commits">Commits</a></li>

  
  <li><a href="/jweyrich/proxylib/network" highlight="repo_network">Network (1)</a></li>

  

  
    
    <li><a href="/jweyrich/proxylib/issues" highlight="issues">Issues (0)</a></li>
  

  
    
    <li><a href="/jweyrich/proxylib/downloads">Downloads (0)</a></li>
  

  
    
    <li><a href="http://wiki.github.com/jweyrich/proxylib/">Wiki (1)</a></li>
  

  <li><a href="/jweyrich/proxylib/graphs" highlight="repo_graphs">Graphs</a></li>

  <li class="contextswitch nochoices">
    <span class="toggle leftwards" >
      <em>Branch:</em>
      <code>master</code>
    </span>
  </li>
</ul>

<div style="display:none" id="pl-description"><p><em class="placeholder">click here to add a description</em></p></div>
<div style="display:none" id="pl-homepage"><p><em class="placeholder">click here to add a homepage</em></p></div>

<div class="subnav-bar">
  
  <ul>
    <li>
      <a href="#" class="dropdown">Switch Branches (1)</a>
      <ul>
        
          
            <li><strong>master &#x2713;</strong></li>
            
      </ul>
    </li>
    <li>
      <a href="#" class="dropdown defunct">Switch Tags (0)</a>
      
    </li>
    <li>
    
    <a href="/jweyrich/proxylib/branches" class="manage">Branch List</a>
    
    </li>
  </ul>
</div>









        
    <div id="repo_details" class="metabox clearfix ">
      <div id="repo_details_loader" class="metabox-loader" style="display:none">Sending Request&hellip;</div>

      
        <div class="pledgie">
          <a href='http://pledgie.com/campaigns/9653'><img alt='Click here to lend your support to: proxylib and make a donation at www.pledgie.com !' src='http://www.pledgie.com/campaigns/9653.png?skin_name=chrome' border='0' /></a>
        </div>
      

      <div id="repository_description" rel="repository_description_edit">
        
          <p>A starting project for a fully async C++ proxy library based on Boost Asio.
            <span id="read_more" style="display:none">&mdash; <a href="#readme">Read more</a></span>
          </p>
        
      </div>
      <div id="repository_description_edit" style="display:none;" class="inline-edit">
        <form action="/jweyrich/proxylib/edit/update" method="post"><div style="margin:0;padding:0"><input name="authenticity_token" type="hidden" value="16c5370b3adc5564c95b2ce627e618c8efd54445" /></div>
          <input type="hidden" name="field" value="repository_description">
          <input type="text" class="textfield" name="value" value="A starting project for a fully async C++ proxy library based on Boost Asio.">
          <div class="form-actions">
            <button class="minibutton"><span>Save</span></button> &nbsp; <a href="#" class="cancel">Cancel</a>
          </div>
        </form>
      </div>

      
      <div class="repository-homepage" id="repository_homepage" rel="repository_homepage_edit">
        <p><a href="http://" rel="nofollow"></a></p>
      </div>
      <div id="repository_homepage_edit" style="display:none;" class="inline-edit">
        <form action="/jweyrich/proxylib/edit/update" method="post"><div style="margin:0;padding:0"><input name="authenticity_token" type="hidden" value="16c5370b3adc5564c95b2ce627e618c8efd54445" /></div>
          <input type="hidden" name="field" value="repository_homepage">
          <input type="text" class="textfield" name="value" value="">
          <div class="form-actions">
            <button class="minibutton"><span>Save</span></button> &nbsp; <a href="#" class="cancel">Cancel</a>
          </div>
        </form>
      </div>

      <div class="rule "></div>

      <div id="url_box" class="url-box">
        <ul class="clone-urls">
          <li id="private_clone_url" style="display:none"><a href="git@github.com:jweyrich/proxylib.git" data-permissions="Read+Write">Private</a></li>
          
            <li id="public_clone_url"><a href="git://github.com/jweyrich/proxylib.git" data-permissions="Read-Only">Read-Only</a></li>
            <li id="http_clone_url"><a href="http://github.com/jweyrich/proxylib.git" data-permissions="Read-Only">HTTP Read-Only</a></li>
          
        </ul>
        <input type="text" spellcheck="false" id="url_field" class="url-field" />
              <span style="display:none" id="url_box_clippy"></span>
      <span id="clippy_tooltip_url_box_clippy" class="clippy-tooltip tooltipped" title="copy to clipboard">
      <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
              width="14"
              height="14"
              class="clippy"
              id="clippy" >
      <param name="movie" value="/flash/clippy.swf?v5"/>
      <param name="allowScriptAccess" value="always" />
      <param name="quality" value="high" />
      <param name="scale" value="noscale" />
      <param NAME="FlashVars" value="id=url_box_clippy&amp;copied=&amp;copyto=">
      <param name="bgcolor" value="#FFFFFF">
      <param name="wmode" value="opaque">
      <embed src="/flash/clippy.swf?v5"
             width="14"
             height="14"
             name="clippy"
             quality="high"
             allowScriptAccess="always"
             type="application/x-shockwave-flash"
             pluginspage="http://www.macromedia.com/go/getflashplayer"
             FlashVars="id=url_box_clippy&amp;copied=&amp;copyto="
             bgcolor="#FFFFFF"
             wmode="opaque"
      />
      </object>
      </span>

        <p id="url_description">This URL has <strong>Read+Write</strong> access</p>
      </div>
    </div>


        

      </div><!-- /.pagehead -->

      









<script type="text/javascript">
  GitHub.currentCommitRef = "master"
  GitHub.currentRepoOwner = "jweyrich"
  GitHub.currentRepo = "proxylib"
  GitHub.downloadRepo = '/jweyrich/proxylib/archives/master'

  

  
</script>










  <div id="commit">
    <div class="group">
        
  <div class="envelope commit">
    <div class="human">
      
        <div class="message"><pre><a href="/jweyrich/proxylib/commit/5b4de026913d0580858254f36456b0e8b57fc6ea">Passing shared_type by reference.</a> </pre></div>
      

      <div class="actor">
        <div class="gravatar">
          
          <img alt="" height="30" src="http://www.gravatar.com/avatar/a7dffcc86140441472cfb6119375a9d7?s=30&amp;d=http%3A%2F%2Fgithub.com%2Fimages%2Fgravatars%2Fgravatar-30.png" width="30" />
        </div>
        <div class="name"><a href="/jweyrich">jweyrich</a> <span>(author)</span></div>
        <div class="date">
          <abbr class="relatize" title="2010-03-23 14:27:49">Tue Mar 23 14:27:49 -0700 2010</abbr>
        </div>
      </div>

      

    </div>
    <div class="machine">
      <span>c</span>ommit&nbsp;&nbsp;<a href="/jweyrich/proxylib/commit/5b4de026913d0580858254f36456b0e8b57fc6ea" hotkey="c">5b4de026913d0580858254f36456b0e8b57fc6ea</a><br />
      <span>t</span>ree&nbsp;&nbsp;&nbsp;&nbsp;<a href="/jweyrich/proxylib/tree/5b4de026913d0580858254f36456b0e8b57fc6ea" hotkey="t">edcea203f928eb42573dcd2258016c94b144d0bb</a><br />
      
        <span>p</span>arent&nbsp;
        
        <a href="/jweyrich/proxylib/tree/1a7650936a33d259112dab423f76996ba447bc96" hotkey="p">1a7650936a33d259112dab423f76996ba447bc96</a>
      

    </div>
  </div>

    </div>
  </div>



  
    <div id="path">
      <b><a href="/jweyrich/proxylib/tree/master">proxylib</a></b> / <a href="/jweyrich/proxylib/tree/master/include">include</a> / <a href="/jweyrich/proxylib/tree/master/include/proxylib">proxylib</a> / debug.h       <span style="display:none" id="clippy_2545">include/proxylib/debug.h</span>
      
      <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
              width="110"
              height="14"
              class="clippy"
              id="clippy" >
      <param name="movie" value="/flash/clippy.swf?v5"/>
      <param name="allowScriptAccess" value="always" />
      <param name="quality" value="high" />
      <param name="scale" value="noscale" />
      <param NAME="FlashVars" value="id=clippy_2545&amp;copied=copied!&amp;copyto=copy to clipboard">
      <param name="bgcolor" value="#FFFFFF">
      <param name="wmode" value="opaque">
      <embed src="/flash/clippy.swf?v5"
             width="110"
             height="14"
             name="clippy"
             quality="high"
             allowScriptAccess="always"
             type="application/x-shockwave-flash"
             pluginspage="http://www.macromedia.com/go/getflashplayer"
             FlashVars="id=clippy_2545&amp;copied=copied!&amp;copyto=copy to clipboard"
             bgcolor="#FFFFFF"
             wmode="opaque"
      />
      </object>
      

    </div>

    <div id="files">
      <div class="file">
        <div class="meta">
          <div class="info">
            <span class="icon"><img alt="Txt" height="16" src="http://assets2.github.com/images/icons/txt.png?ca4dc080a760e83060a978a6592f45642990f642" width="16" /></span>
            <span class="mode" title="File Mode">100644</span>
            
              <span>61 lines (53 sloc)</span>
            
            <span>1.668 kb</span>
          </div>
          <ul class="actions">
            
              <li><a id="file-edit-link" href="#" rel="/jweyrich/proxylib/file-edit/__ref__/include/proxylib/debug.h">edit</a></li>
            
            <li><a href="/jweyrich/proxylib/raw/master/include/proxylib/debug.h" id="raw-url">raw</a></li>
            
              <li><a href="/jweyrich/proxylib/blame/master/include/proxylib/debug.h">blame</a></li>
            
            <li><a href="/jweyrich/proxylib/commits/master/include/proxylib/debug.h">history</a></li>
          </ul>
        </div>
        
  <div class="data syntax type-cpp">
    
      <table cellpadding="0" cellspacing="0">
        <tr>
          <td>
            
            <pre class="line_numbers">
<span id="LID1" rel="#L1">1</span>
<span id="LID2" rel="#L2">2</span>
<span id="LID3" rel="#L3">3</span>
<span id="LID4" rel="#L4">4</span>
<span id="LID5" rel="#L5">5</span>
<span id="LID6" rel="#L6">6</span>
<span id="LID7" rel="#L7">7</span>
<span id="LID8" rel="#L8">8</span>
<span id="LID9" rel="#L9">9</span>
<span id="LID10" rel="#L10">10</span>
<span id="LID11" rel="#L11">11</span>
<span id="LID12" rel="#L12">12</span>
<span id="LID13" rel="#L13">13</span>
<span id="LID14" rel="#L14">14</span>
<span id="LID15" rel="#L15">15</span>
<span id="LID16" rel="#L16">16</span>
<span id="LID17" rel="#L17">17</span>
<span id="LID18" rel="#L18">18</span>
<span id="LID19" rel="#L19">19</span>
<span id="LID20" rel="#L20">20</span>
<span id="LID21" rel="#L21">21</span>
<span id="LID22" rel="#L22">22</span>
<span id="LID23" rel="#L23">23</span>
<span id="LID24" rel="#L24">24</span>
<span id="LID25" rel="#L25">25</span>
<span id="LID26" rel="#L26">26</span>
<span id="LID27" rel="#L27">27</span>
<span id="LID28" rel="#L28">28</span>
<span id="LID29" rel="#L29">29</span>
<span id="LID30" rel="#L30">30</span>
<span id="LID31" rel="#L31">31</span>
<span id="LID32" rel="#L32">32</span>
<span id="LID33" rel="#L33">33</span>
<span id="LID34" rel="#L34">34</span>
<span id="LID35" rel="#L35">35</span>
<span id="LID36" rel="#L36">36</span>
<span id="LID37" rel="#L37">37</span>
<span id="LID38" rel="#L38">38</span>
<span id="LID39" rel="#L39">39</span>
<span id="LID40" rel="#L40">40</span>
<span id="LID41" rel="#L41">41</span>
<span id="LID42" rel="#L42">42</span>
<span id="LID43" rel="#L43">43</span>
<span id="LID44" rel="#L44">44</span>
<span id="LID45" rel="#L45">45</span>
<span id="LID46" rel="#L46">46</span>
<span id="LID47" rel="#L47">47</span>
<span id="LID48" rel="#L48">48</span>
<span id="LID49" rel="#L49">49</span>
<span id="LID50" rel="#L50">50</span>
<span id="LID51" rel="#L51">51</span>
<span id="LID52" rel="#L52">52</span>
<span id="LID53" rel="#L53">53</span>
<span id="LID54" rel="#L54">54</span>
<span id="LID55" rel="#L55">55</span>
<span id="LID56" rel="#L56">56</span>
<span id="LID57" rel="#L57">57</span>
<span id="LID58" rel="#L58">58</span>
<span id="LID59" rel="#L59">59</span>
<span id="LID60" rel="#L60">60</span>
<span id="LID61" rel="#L61">61</span>
</pre>
          </td>
          <td width="100%">
            
              <div class="highlight"><pre><div class="line" id="LC1"><span class="cp">#pragma once</span></div><div class="line" id="LC2"><br/></div><div class="line" id="LC3"><span class="cp">#include &lt;cstdio&gt;</span></div><div class="line" id="LC4"><br/></div><div class="line" id="LC5"><span class="cp">#define DEBUG_0 0</span></div><div class="line" id="LC6"><span class="cp">#define DEBUG_1 1</span></div><div class="line" id="LC7"><span class="cp">#define _M_DEBUG_ENABLED(flag) \</span></div><div class="line" id="LC8"><span class="cp">	(DEBUG_ ## flag != 0)</span></div><div class="line" id="LC9"><br/></div><div class="line" id="LC10"><span class="cp">#ifdef DEBUG</span></div><div class="line" id="LC11"><span class="cp">#define _M_DTRACE \</span></div><div class="line" id="LC12"><span class="cp">	printf(&quot;%s %s:%d %s called\n&quot;, &quot;TRACE&quot;, __FILE__, __LINE__, __func__) </span><span class="c1">//__PRETTY_FUNCTION__</span></div><div class="line" id="LC13"><span class="cp">#define _M_DLOG(format, args...) \</span></div><div class="line" id="LC14"><span class="cp">	printf(&quot;%s:%d &quot; format &quot;\n&quot;, __FILE__, __LINE__, ##args)</span></div><div class="line" id="LC15"><span class="cp">#define _M_DDEBUG(format, args...) \</span></div><div class="line" id="LC16"><span class="cp">	printf(&quot;%s %s:%d &quot; format &quot;\n&quot;, &quot;DEBUG&quot;, __FILE__, __LINE__, ##args)</span></div><div class="line" id="LC17"><span class="cp">#define _M_DWARN(format, args...) \</span></div><div class="line" id="LC18"><span class="cp">	printf(&quot;%s %s:%d &quot; format &quot;\n&quot;, &quot;WARN&quot;, __FILE__, __LINE__, ##args)</span></div><div class="line" id="LC19"><span class="cp">#define _M_DERROR(format, args...) \</span></div><div class="line" id="LC20"><span class="cp">	printf(&quot;%s %s:%d &quot; format &quot;\n&quot;, &quot;ERROR&quot;, __FILE__, __LINE__, ##args)</span></div><div class="line" id="LC21"><span class="cp">#define _M_DFATAL(format, args...) \</span></div><div class="line" id="LC22"><span class="cp">	printf(&quot;%s %s:%d &quot; format &quot;\n&quot;, &quot;FATAL&quot;, __FILE__, __LINE__, ##args)</span></div><div class="line" id="LC23"><br/></div><div class="line" id="LC24"><span class="cp">#define _M_DPRINTF(flag, format, args...) \</span></div><div class="line" id="LC25"><span class="cp">	do { \</span></div><div class="line" id="LC26"><span class="cp">		if (_M_DEBUG_ENABLED(flag)) { \</span></div><div class="line" id="LC27"><span class="cp">			printf(format, ##args); \</span></div><div class="line" id="LC28"><span class="cp">		} \</span></div><div class="line" id="LC29"><span class="cp">	} while (0)</span></div><div class="line" id="LC30"><br/></div><div class="line" id="LC31"><span class="cp">#define _M_DPRINTF_INDENT(flag, indent, format, args...) \</span></div><div class="line" id="LC32"><span class="cp">	do { \</span></div><div class="line" id="LC33"><span class="cp">		if (_M_DEBUG_ENABLED(flag)) { \</span></div><div class="line" id="LC34"><span class="cp">			printf(&quot;%*s&quot; format, indent, &quot; &quot;, ##args); \</span></div><div class="line" id="LC35"><span class="cp">		} \</span></div><div class="line" id="LC36"><span class="cp">	} while (0)</span></div><div class="line" id="LC37"><br/></div><div class="line" id="LC38"><span class="cp">#else </span><span class="c1">// ifdef DEBUG</span></div><div class="line" id="LC39"><span class="cp">#define _M_DTRACE</span></div><div class="line" id="LC40"><span class="cp">#define _M_DLOG(format, args...)</span></div><div class="line" id="LC41"><span class="cp">#define _M_DDEBUG(format, args...)</span></div><div class="line" id="LC42"><span class="cp">#define _M_DWARN(format, args...)</span></div><div class="line" id="LC43"><span class="cp">#define _M_DERROR(format, args...)</span></div><div class="line" id="LC44"><span class="cp">#define _M_DFATAL(format, args...)</span></div><div class="line" id="LC45"><span class="cp">#define _M_DPRINTF(format, args...)</span></div><div class="line" id="LC46"><span class="cp">#define _M_DPRINTF_INDENT(format, args...)</span></div><div class="line" id="LC47"><span class="cp">#endif </span><span class="c1">// ifdef DEBUG</span></div><div class="line" id="LC48"><br/></div><div class="line" id="LC49"><span class="c1">//</span></div><div class="line" id="LC50"><span class="c1">// Use these</span></div><div class="line" id="LC51"><span class="c1">//</span></div><div class="line" id="LC52"><span class="cp">#define DEBUG_ENABLED	_M_DEBUG_ENABLED</span></div><div class="line" id="LC53"><span class="cp">#define DTRACE			_M_DTRACE</span></div><div class="line" id="LC54"><span class="cp">#define DLOG			_M_DLOG</span></div><div class="line" id="LC55"><span class="cp">#define DDEBUG			_M_DDEBUG</span></div><div class="line" id="LC56"><span class="cp">#define DWARN			_M_DWARN</span></div><div class="line" id="LC57"><span class="cp">#define DERROR			_M_DERROR</span></div><div class="line" id="LC58"><span class="cp">#define DFATAL			_M_DFATAL</span></div><div class="line" id="LC59"><span class="cp">#define DPRINTF			_M_DPRINTF</span></div><div class="line" id="LC60"><span class="cp">#define DPRINTF2		_M_DPRINTF_INDENT</span></div><div class="line" id="LC61"><br/></div></pre></div>
            
          </td>
        </tr>
      </table>
    
  </div>


      </div>
    </div>

  


    </div>
  
      

      <div class="push"></div>
    </div>

    <div id="footer">
      <div class="site">
        <div class="info">
          <div class="links">
            <a href="http://github.com/blog"><b>Blog</b></a> |
            <a href="http://support.github.com/">Support</a> |
            <a href="http://github.com/training">Training</a> |
            <a href="http://github.com/contact">Contact</a> |
            <a href="http://develop.github.com">API</a> |
            <a href="http://status.github.com">Status</a> |
            <a href="http://twitter.com/github">Twitter</a> |
            <a href="http://help.github.com">Help</a> |
            <a href="http://github.com/security">Security</a>
          </div>
          <div class="company">
            &copy;
            2010
            <span id="_rrt" title="0.07731s from fe1.rs.github.com">GitHub</span> Inc.
            All rights reserved. |
            <a href="/site/terms">Terms of Service</a> |
            <a href="/site/privacy">Privacy Policy</a>
          </div>
        </div>
        <div class="sponsor">
          <div>
            Powered by the <a href="http://www.rackspace.com ">Dedicated
            Servers</a> and<br/> <a href="http://www.rackspacecloud.com">Cloud
            Computing</a> of Rackspace Hosting<span>&reg;</span>
          </div>
          <a href="http://www.rackspace.com">
            <img alt="Dedicated Server" src="http://assets2.github.com/images/modules/footer/rackspace_logo.png?ca4dc080a760e83060a978a6592f45642990f642" />
          </a>
        </div>
      </div>
    </div>

    <script>window._auth_token = "16c5370b3adc5564c95b2ce627e618c8efd54445"</script>
    
    
  </body>
</html>

