/* See LICENSE file for copyright and license details. */

#define TERMINAL "tabbed -c -r 2 st -w ''"
#define WEB_BROWSER "librewolf"
#define PRIVATE_WEB_BROWSER "librewolf --private-window"
#define LOCKSCREEN_SCRIPT "~/.local/bin/lockscreen"
#define KEYBOARD_SCRIPT "~/.local/bin/kb"
#define EMOJI_SCRIPT "~/.local/bin/emoji-selector"
#define SCREENSHOT_SCRIPT "~/.local/bin/screenshot"
#define PASSWORD_MANAGER_SCRIPT "~/.local/bin/passmenu-custom --type -c -l 20 -p '🔑: '"
#define MONITOR_MANAGER_SCRIPT "~/.local/bin/monitor-manager"
#define EXECUTE_SCRIPTS_SCRIPT "~/.local/bin/scripts"
#define RECORD_SCRIPT "~/.local/bin/record"
#define REBOOT_SCRIPT "sudo reboot"
#define SHUTDOWN_SCRIPT "sudo poweroff"

/* appearance */
static unsigned int borderpx        = 1;        /* border pixel of windows */
static unsigned int snap            = 32;       /* snap pixel */
static unsigned int gappih    	    = 20;       /* horiz inner gap between windows */
static unsigned int gappiv    	    = 10;       /* vert inner gap between windows */
static unsigned int gappoh    	    = 10;       /* horiz outer gap between windows and screen edge */
static unsigned int gappov    	    = 30;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static int showbar                  = 1;        /* 0 means no bar */
static int topbar                   = 1;        /* 0 means bottom bar */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */
#define ICONSIZE 		      24   	/* icon size */
#define ICONSPACING 		      10 	/* space between icon and title */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int swterminheritfs    = 1;        /* 1 terminal inherits fullscreen on unswallow, 0 otherwise */
static const char mainfont[]        = "JetBrainsMono Nerd Font:pixelsize=22:antialias=true:autohint=true";
static const char *fonts[]          = { mainfont };
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
	/*                    fg           bg           border   */
	[SchemeNorm] =      { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel]  =      { selfgcolor,  selbgcolor,  selbordercolor  },
	[SchemeStatus]  =   { normfgcolor, normbgcolor, "#000000"  }, // Statusbar right {text,background,not used}
	//[SchemeTagsSel]  =  { selfgcolor,  selbgcolor,  "#000000"  }, // Tagbar left selected {text,background,not used}
	[SchemeTagsSel]  =  { selfgcolor,  selbordercolor,"#000000"  }, // Tagbar left selected {text,background,not used}
	[SchemeTagsNorm]  = { normfgcolor, normbgcolor, "#000000"  }, // Tagbar left unselected {text,background,not used}
	//[SchemeInfoSel]  =  { selfgcolor,  selbgcolor,  "#000000"  }, // infobar middle  selected {text,background,not used}
	[SchemeInfoSel]  =  { normbgcolor, selbordercolor,"#000000"  }, // infobar middle  selected {text,background,not used}
	[SchemeInfoNorm]  = { normfgcolor, normbgcolor, "#000000"  }, // infobar middle  unselected {text,background,not used}
};

static const unsigned int baralpha = OPAQUE;
//static const unsigned int sidebaralpha = 0xd0;
static const unsigned int sidebaralpha = OPAQUE;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
    /*               fg      bg        border*/
    [SchemeNorm]      = { OPAQUE, baralpha, borderalpha },
    [SchemeSel]       = { OPAQUE, baralpha, borderalpha },
    [SchemeStatus]    = { OPAQUE, sidebaralpha, borderalpha },
    [SchemeTagsSel]   = { OPAQUE, baralpha, borderalpha },
    [SchemeTagsNorm]  = { OPAQUE, sidebaralpha, borderalpha },
    [SchemeInfoSel]   = { OPAQUE, baralpha, borderalpha },
    [SchemeInfoNorm]  = { OPAQUE, sidebaralpha, borderalpha },
};


/* tagging */
static const char *tags[] = { "", "󰈹", "", "󰈙", "󰐨", "", "󰕧", "󰩹", "" };
static const char *tagsalt[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const int momentaryalttags = 0; /* 1 means alttags will show only when key is held down*/

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title            tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",     NULL,       NULL,            0,         1,          0,           0,        -1 },
	{ "Firefox",  NULL,       NULL,            1 << 8,    0,          0,          -1,        -1 },
	{ "St",       NULL,       NULL,            0,         0,          1,           0,        -1 },
	{ NULL,       NULL,       "Event Tester",  0,         0,          0,           1,        -1 }, /* xev */
	{ "tabbed",   NULL,       NULL,            0,         0,          1,           -1,       -1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
#include "shift-tools.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "D[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-c", "-l", "20",  "-p", "Run: ", NULL }; 
static const char *termcmd[]  = { "st", NULL };

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "normbgcolor",        STRING,  &normbgcolor },
		{ "normbordercolor",    STRING,  &normbordercolor },
		{ "normfgcolor",        STRING,  &normfgcolor },
		{ "selbgcolor",         STRING,  &selbgcolor },
		{ "selbordercolor",     STRING,  &selbordercolor },
		{ "selfgcolor",         STRING,  &selfgcolor },
		{ "borderpx",          	INTEGER, &borderpx },
		{ "gappih",          	INTEGER, &gappih },
		{ "gappiv",          	INTEGER, &gappiv },
		{ "gappoh",          	INTEGER, &gappoh },
		{ "gappov",          	INTEGER, &gappov },
		{ "smartgaps",          INTEGER, &smartgaps },
		{ "snap",               INTEGER, &snap },
		{ "showbar",          	INTEGER, &showbar },
		{ "topbar",          	INTEGER, &topbar },
		{ "nmaster",          	INTEGER, &nmaster },
		{ "resizehints",       	INTEGER, &resizehints },
		{ "mfact",      	FLOAT,   &mfact },
};


#include "movestack.c"
#include <X11/XF86keysym.h> /* media keys & more */
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ ALTKEY,			XK_space,  spawn,	   {.v = dmenucmd} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_braceleft,incnmaster,   {.i = +1 } },
	{ MODKEY,                       XK_braceright,incnmaster,  {.i = -1 } },
        { MODKEY,             		XK_Escape, resetlayout,    {0} },
	{ MODKEY,                       XK_Escape, resetnmaster,   {0} },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY|ControlMask,		XK_h,      shiftviewclients, {.i = -1} },
	{ MODKEY|ControlMask,		XK_l,      shiftviewclients, {.i = +1} },	
	{ MODKEY,                       XK_Return, focusmaster,    {0} },
      /*{ MODKEY|ALTKEY,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|ALTKEY|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|ALTKEY,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|ALTKEY|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|ALTKEY,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|ALTKEY|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|ALTKEY,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|ALTKEY|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|ALTKEY,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|ALTKEY|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|ALTKEY,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|ALTKEY|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|ALTKEY,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|ALTKEY|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|ALTKEY,              XK_0,      togglegaps,     {0} },
	{ MODKEY|ALTKEY|ShiftMask,    XK_0,      defaultgaps,    {0} },*/
      //{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,             		XK_x,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_m,      setlayouttoggle,{.v = &layouts[1]} },
	{ MODKEY,                       XK_d,      setlayouttoggle,{.v = &layouts[4]} },
	{ MODKEY,                       XK_v,      setlayouttoggle,{.v = &layouts[6]} },
	{ MODKEY,                       XK_Tab,    setlayouttoggle,{.v = &layouts[7]} },
	{ MODKEY,			XK_minus,  cyclelayout,    {.i = -1 } },
	{ MODKEY,           		XK_plus,   cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_s,      winview,        {0} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_n,      togglealttag,   {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY,		        XK_r, 	   spawn,          SHCMD(TERMINAL) },
	{ MODKEY,		        XK_w, 	   spawn,          SHCMD(WEB_BROWSER) },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD(PRIVATE_WEB_BROWSER) },
	{ MODKEY|ShiftMask,		XK_l, 	   spawn,          SHCMD(LOCKSCREEN_SCRIPT) },
	{ MODKEY,                       XK_space,  spawn,      	   SHCMD(KEYBOARD_SCRIPT) },
	{ MODKEY|ALTKEY,		XK_period, spawn,	   SHCMD(EMOJI_SCRIPT) },
	{ MODKEY|ShiftMask,		XK_s,  	   spawn,	   SHCMD(SCREENSHOT_SCRIPT) },
	{ MODKEY|ShiftMask,		XK_m, 	   spawn,          SHCMD(MONITOR_MANAGER_SCRIPT) },
	{ MODKEY|ShiftMask,		XK_d, 	   spawn,          SHCMD(PASSWORD_MANAGER_SCRIPT) },
	{ MODKEY|ShiftMask,		XK_e, 	   spawn,          SHCMD(EXECUTE_SCRIPTS_SCRIPT) },
	{ MODKEY|ShiftMask,		XK_r, 	   spawn,          SHCMD(RECORD_SCRIPT) },
	{ ControlMask|ShiftMask|ALTKEY, XK_Delete, spawn,	   SHCMD("killall Xorg") },
	{ ControlMask|ShiftMask|ALTKEY, XK_Page_Up,spawn,	   SHCMD(REBOOT_SCRIPT) },
	{ ControlMask|ShiftMask|ALTKEY, XK_Page_Down, spawn,	   SHCMD(SHUTDOWN_SCRIPT) },
	{ 0, XF86XK_Sleep,	   	   spawn,	   SHCMD(LOCKSCREEN_SCRIPT) },
	{ 0, XF86XK_ScreenSaver,	   spawn, 	   SHCMD(LOCKSCREEN_SCRIPT) },
	{ 0, XF86XK_MonBrightnessDown,	   spawn,	   SHCMD("light -U 10 && pkill -RTMIN+3 dwmblocks") },
	{ 0, XF86XK_MonBrightnessUp,	   spawn,	   SHCMD("light -A 10 && pkill -RTMIN+3 dwmblocks") },
	{ 0, XF86XK_AudioRaiseVolume,	   spawn, 	   SHCMD("pamixer -u && pamixer -i 5 && pkill -RTMIN+4 dwmblocks")},
	{ 0, XF86XK_AudioLowerVolume,	   spawn, 	   SHCMD("pamixer -u && pamixer -d 5 && pkill -RTMIN+4 dwmblocks")},
	{ 0, XF86XK_AudioMute,		   spawn, 	   SHCMD("pamixer -t 		     && pkill -RTMIN+4 dwmblocks")},
	{ 0, XF86XK_AudioPlay,		   spawn, 	   SHCMD("playerctl play-pause") },
	{ MODKEY, 	XK_Down,   	   spawn, 	   SHCMD("playerctl play-pause") },
	{ 0, XF86XK_AudioPrev, 		   spawn,	   SHCMD("playerctl previous") },
	{ MODKEY, 	XK_Left,   	   spawn, 	   SHCMD("playerctl previous") },
	{ 0, XF86XK_AudioNext,		   spawn,	   SHCMD("playerctl next") },
	{ MODKEY, 	XK_Right,   	   spawn, 	   SHCMD("playerctl next") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
