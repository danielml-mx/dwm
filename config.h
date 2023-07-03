/* by DanielML*/

/* constants */
#define TERMINAL "st"
#define TERMINAL_BIGFONT "st -f 'Roboto Mono:pixelsize=19.5:antialias=true:autohint=true'"
//#define TERMCLASS "St"
#define FILE_BROWSER "~/.local/bin/lfub" /* terminal browsers only */
#define WEB_BROWSER "librewolf"
#define PRIVATE_WEB_BROWSER "librewolf --private-window"
#define TEXT_EDITOR "nvim"
#define MAIL_CLIENT "neomutt"
#define CALENDAR "calcurse"
#define LOCKSCREEN_SCRIPT "~/.local/bin/lockscreen"
#define SHUTDOWN_SCRIPT "sudo poweroff"
#define REBOOT_SCRIPT "sudo reboot"
#define WIFI_STATUS_SCRIPT "~/.local/bin/wifi_status"
#define RFKILL_SCRIPT "notify-send -a 'WPA Supplicant' 'Status' \"$(rfkill -o TYPE-DESC,ID,SOFT --noheadings)\""
#define EMOJI_SCRIPT "~/.local/bin/emoji-selector"
#define MUSIC_STATUS_SCRIPT "cmus-remote -Q && ~/.config/cmus/cmus-album-art.sh force"
#define SCREENSHOT_SCRIPT "~/.local/bin/screenshot"
#define PASSWORD_MANAGER_SCRIPT "~/.local/bin/passmenu-custom --type -c -l 20"
#define EXECUTE_SCRIPTS_SCRIPT "~/.local/bin/scripts"
#define RECORD_SCRIPT "~/.local/bin/record"

/* appearance | properties changed by xresources patch */
static unsigned int borderpx  = 1;        /* border pixel of windows */
static unsigned int snap      = 32;       /* snap pixel */
static const char *fonts[]          = { "Roboto Mono Light:style=Light:size=9.5" , "Symbols Nerd Font:pixelzise=9.5:antialias=true:autohint=true", "NotoColorEmoji:size=10", "FontAwesome:size=10"};
static const char dmenufont[]       = "Roboto Mono:size=10";
static char normbgcolor[]           = "#222222";	/* tag background color */
static char normbordercolor[]       = "#444444";	/* inactive tag border color */
static char normfgcolor[]           = "#bbbbbb";	/* font color */
static char selfgcolor[]            = "#eeeeee";	/* tag font color : default is eeeeee*/
static char selbordercolor[]        = "#005577";	/* top bar color & active window border  */ 
static char selbgcolor[]            = "#005577";        /* ? */
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },

};
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */

/* bar settings */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 1;        /* 0 means bottom bar */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char *altbarcmd        = "killall polybar ; polybar bar &"; /* Alternate bar launch command */
//static const char *altbarcmd        = ""; /* Alternate bar launch command */


/* alpha */
//static const unsigned int baralpha = 0xd0;
static const unsigned int baralpha = -1;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
       /*               fg      bg        border     */
       [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
       [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};


/* vanitygaps */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	//{ "Gimp",    NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "Librewolf", NULL,     NULL,         1 << 8,    0,          0,          -1,        -1 },
	{ "St",      NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static float mfact     = 0.50; /* factor of master area size [0.05..0.95] */ /* 0.55 */ /* 0.50 so that windows take up half screen by default*/
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

/* fibonacci patch */
/*#include "fibonacci.c"*/
/*#include "grid.c"*/
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split v
ertically */
#include "vanitygaps.c"

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
        { "><>",      NULL },    /* no layout function means floating behavior
*/
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

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-c", "-l", "20", NULL }; 
static const char *termcmd[] = { "st", NULL };
static const char *www[] = { WEB_BROWSER, NULL };

/* Xresources preferences to load at startup */
ResourcePref resources[] = {
               { "normbgcolor",        STRING,  &normbgcolor },
               { "normbordercolor",    STRING,  &normbordercolor },
               { "normfgcolor",        STRING,  &normfgcolor },
               { "selbgcolor",         STRING,  &selbgcolor },
               { "selbordercolor",     STRING,  &selbordercolor },
               { "selfgcolor",         STRING,  &selfgcolor },
               { "borderpx",           INTEGER, &borderpx },
               { "snap",               INTEGER, &snap },
               { "showbar",            INTEGER, &showbar },
               { "topbar",             INTEGER, &topbar },
               { "nmaster",            INTEGER, &nmaster },
               { "resizehints",        INTEGER, &resizehints },
               { "mfact",              FLOAT,   &mfact },
	       //{ "baralpha",	       INTEGER, &baralpha },
};

/* Include patches */
#include "shiftview.c"
#include <X11/XF86keysym.h> /* media keys & more */

#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	/*{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },*/
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_braceleft,incnmaster,   {.i = +1 } },
	{ MODKEY,                       XK_braceright,incnmaster,  {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	/*{ MODKEY,                       XK_Return, spawn,          SHCMD(TERMINAL " -e " FILE_BROWSER ) },*/
	{ MODKEY,                       XK_Tab,    view,           {0} },
	/*{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },*/
        { MODKEY,                       XK_x,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	/*{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },*/
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,          {0} },

	/* ADDED KEYBINDINGS */
        /* open term file browser */
	{ MODKEY,		        XK_e, 	   spawn,          SHCMD(TERMINAL " -e " FILE_BROWSER) },

        /* open terminal && open terminal bigfont*/
	{ MODKEY,		        XK_r, 	   spawn,          {.v = termcmd } },
	{ MODKEY|ControlMask,		XK_r, 	   spawn,          SHCMD(TERMINAL_BIGFONT) },

	/* dunst */


        /* dmenu */
	{ ALTKEY,			XK_space,  spawn,	   {.v = dmenucmd} },

        /* take screenshot */
	{ MODKEY|ShiftMask,		XK_s,  	   spawn,	   SHCMD(SCREENSHOT_SCRIPT) },

        /* lock screen */
	{ MODKEY|ShiftMask,		XK_l, 	   spawn,          SHCMD(LOCKSCREEN_SCRIPT) },

        /* password manager */
	{ MODKEY|ShiftMask,		XK_p, 	   spawn,          SHCMD(PASSWORD_MANAGER_SCRIPT) },

        /* record */
	{ MODKEY|ShiftMask,		XK_r, 	   spawn,          SHCMD(RECORD_SCRIPT) },

        /* execute scripts */
	{ MODKEY|ShiftMask,		XK_e, 	   spawn,          SHCMD(EXECUTE_SCRIPTS_SCRIPT) },

        /* open web browser */
	{ MODKEY,		        XK_w, 	   spawn,          {.v = www } },

        /* open private web browser */
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD(PRIVATE_WEB_BROWSER) },

        /* calendar */
	{ MODKEY,             		XK_c,      spawn,          SHCMD(TERMINAL " -e " CALENDAR) },

        /* mail */
	{ MODKEY,             		XK_m,      spawn,          SHCMD(TERMINAL " -e " MAIL_CLIENT) },

        /* move one workspace to the left */
	{ MODKEY|ControlMask,		XK_h,   shiftview,	   {.i = -1} },								

        /* move one workspace to the right */
        { MODKEY|ControlMask,		XK_l,  shiftview,	   {.i = +1} },

	/* LAYOUTS */	
        { MODKEY,               XK_t,      setlayout,      {.v = &layouts[0]} }, /* tiling */

        /* vanity gaps */
	/* (honestly never used */

        { MODKEY|ALTKEY,                XK_0,      togglegaps,     {0} },
        { MODKEY|ALTKEY|ShiftMask,      XK_0,      defaultgaps,    {0} },

	
	/* cycle layout */
	{ MODKEY,	    XK_minus,  cyclelayout,    {.i = -1 } },
	{ MODKEY,           XK_plus,   cyclelayout,    {.i = +1 } },

	/* move stack */
        { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
        { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },

	/* reset layout + nmaster */
	{ MODKEY,                       XK_Escape, resetlayout,    {0} },

	/* emoji script */
	{ MODKEY|ALTKEY,		XK_period, spawn,	   SHCMD(EMOJI_SCRIPT) },

	/* volume */
	{ 0, XF86XK_AudioRaiseVolume,	   spawn, 	   SHCMD("pamixer -i 5")},
	{ 0, XF86XK_AudioLowerVolume,	   spawn, 	   SHCMD("pamixer -d 5")},
	{ 0, XF86XK_AudioMute,		   spawn, 	   SHCMD("pamixer -t")},
	{ 0, XF86XK_Launch1,		   spawn, 	   SHCMD("pamixer -t")},
	{ 0, XF86XK_AudioPlay,		   spawn, 	   SHCMD("playerctl play-pause") },
	{ 0, XF86XK_AudioPrev, 		   spawn,	   SHCMD("playerctl previous") },
	{ 0, XF86XK_AudioNext,		   spawn,	   SHCMD("playerctl next") },
	{ 0, XF86XK_AudioStop,		   spawn,	   SHCMD("playerctl next") },


	/* transparency update:*/
	/* toggle opacity of focused window */
	{ MODKEY|ShiftMask,		XK_o,	spawn,		SHCMD("picom-trans -c -t")},

	/* exit */
	{ ControlMask|ShiftMask|ALTKEY, XK_Delete, spawn,	   SHCMD("killall wireplumber Xorg") },
	/* sleep */
	{ ControlMask|ShiftMask|ALTKEY, XK_Insert, spawn,	   SHCMD(LOCKSCREEN_SCRIPT " & sleep 1 && echo mem | sudo tee /sys/power/state") },
        /* reboot */
	{ ControlMask|ShiftMask|ALTKEY, XK_Page_Up, spawn,	   SHCMD(REBOOT_SCRIPT) },
        /* shut down */
	{ ControlMask|ShiftMask|ALTKEY, XK_Page_Down, spawn,	   SHCMD(SHUTDOWN_SCRIPT) },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

