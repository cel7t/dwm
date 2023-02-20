/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 10;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {"Iosevka:size=16", "Noto Color Emoji:pixelsize=22"};
//{ "M+ 1m:size=14", "Noto Color Emoji:pixelsize=22" };
static const char dmenufont[]       = "Iosevka:size=16";
static const char menuconf[]		= "$HOME/.9menu";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_blue1[]       = "#225599";
static const char col_blue2[]       = "#4477bb";
static const char col_blue3[]       = "#77aaee";
static const char col_blue4[]       = "#003377";
static const char col_ametext[]     = "#25141b";
static const char col_ameborder[]       = "#4b3946";
static const char col_amebg[]   = "#466bb8";
static const char col_ameseltext[]  = "#fdfcec";
static const char col_ameselbg[]    = "#fdf5da";
static const char col_ameselborder[]  = "#b4c7e0";
static const char col_amedark[]   = "#333D5D";
static const char col_sel[]        = "#114488";
static const char col_swfgn[]	= "#f5f5f5";
static const char col_swbgn[]	= "#1a1a1a"; //"#6A3B0B";
static const char col_swbdn[]	= "#caa263";
static const char col_swfgs[]	= "#f5f5f5"; //"#adafae";
static const char col_swbgs[]	= "#3585A9"; //"#2e2f31";
static const char col_swbds[]	= "#fdc969";

static const char col_fgn[] = "#fefefe";
static const char col_bgn[] = "#120f14";
static const char col_bdn[] = "#aa8ca4";
static const char col_fgs[] = "#2a2a2a";
static const char col_bgs[] = "#af7182"; //#9a99e7";
static const char col_bds[] = "#663399";

static const char color0[] = "#0f0e0c";
static const char color1[] = "#8D767E";
static const char color2[] = "#525966";
static const char color3[] = "#A68972";
static const char color4[] = "#5B6474";
static const char color5[] = "#6A6A70";
static const char color6[] = "#717884";
static const char color7[] = "#fefefe";
static const char color8[] = "#2b2822";
static const char color9[] = "#c8889e";
static const char color10[] = "#5e7090";
static const char color11[] = "#e9b082";
static const char color12[] = "#687ea4";
static const char color13[] = "#7b7b9f";
static const char color14[] = "#8397bb";
static const char color15[] = "#f7fdff";


static const char *colors[][3]      = {
	/*               fg          bg          border   */
	[SchemeNorm] = { color7, 		color0,			color4 },
	[SchemeSel]  = { color8,		col_bgs,		color3 },
};

/* tagging */
static const char *tags[] = { "I", "II", "III", "IV", "V", "VI" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      	instance    	title         tags mask     isfloating   monitor */
	{ "Gimp",     		NULL,       NULL,       			 0,           1,         -1 },
	{ "mpv",     		  NULL,       NULL,       			 0,           1,         -1 },
	{ NULL,     			NULL,       "dclock",   			 0,        	  1,         -1 },
	{ "Tor Browser",  NULL,       NULL,       		 	 0,        	  1,         -1 },
	{ "Firefox",  		NULL,       NULL,       		  1 << 8,     	0,  			 -1 },
  //	{ NULL,     			NULL,       "Emacs Capture",  1 << 6,       0,         -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 2;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"
#include "tatami.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "[@]",	spiral },
	{ "[\\]",	dwindle },
	{ "|+|",	tatami },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG)                                                \
	{ ALTKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ ALTKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ ALTKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ ALTKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_bgn, "-nf", col_fgn, "-sb", col_bgs, "-sf", col_fgs, NULL };
static const char *roficmd[] = { "rofi", "-show", "combi", NULL };
static const char *printwcmd[] = { "scrotum", "-w", NULL };
static const char *printscmd[] = { "scrotum", "-s", NULL };
static const char *printfcmd[] = { "scrotum", "-f", NULL };
static const char *zuttycmd[]  = { "zutty", NULL };
static const char *termcmd[]  = { "xterm", NULL };
static const char *menucmd[]  = { "9menu", "-file", menuconf, NULL };
static const char *browscmd[]  = { "librewolf", NULL };
static const char *emacscmd[]  = { "smacs", NULL };
static const char *filecmd[]  = { "Thunar", NULL };
static const char *volucmd[]  = { "amixer", "set", "Master", "5%+", NULL };
static const char *voldcmd[]  = { "amixer", "set", "Master", "5%-", NULL };
static const char *volmcmd[]  = { "amixer", "set", "Master", "toggle", NULL };
static const char *lightucmd[]  = { "light", "-A", "5", NULL };
static const char *lightdcmd[]  = { "light", "-U", "5", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ ALTKEY|ShiftMask,                       XK_p,      spawn,          {.v = roficmd } },
	{ ALTKEY,             XK_p,      spawn,          {.v = dmenucmd } },
	{ ALTKEY,                       XK_Home,      spawn,		 {.v = printwcmd } },
	{ ALTKEY|ShiftMask,             XK_Home,      spawn,		 {.v = printscmd } },
	{ ALTKEY|ControlMask,						XK_Home,      spawn,		 {.v = printfcmd } },
	{ ALTKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ ALTKEY|ControlMask,           XK_c,	   spawn,          {.v = browscmd } },
	{ ALTKEY|ControlMask,           XK_e,	   spawn,          {.v = emacscmd } },
	{ ALTKEY|ControlMask,           XK_d,	   spawn,          {.v = filecmd } },
	{ ALTKEY|ControlMask,           XK_t,	   spawn,          {.v = zuttycmd } },
	{ 0,					0x1008ff11,	   spawn,						{.v = voldcmd } },
	{ 0,					0x1008ff13,	   spawn,						{.v = volucmd } },
	{ 0,					0x1008ff12,			spawn,					{.v = volmcmd } },
	{ ALTKEY,			0x1008ff13,	   spawn,						{.v = lightucmd } },
	{ ALTKEY,			0x1008ff11,	   spawn,						{.v = lightdcmd } },
	{ ALTKEY,                       XK_b,      togglebar,      {0} },
	{ ALTKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ ALTKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ ALTKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ ALTKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ ALTKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ ALTKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ ALTKEY,                       XK_Tab,	   zoom,           {0} },
	{ ALTKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ ALTKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ ALTKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ ALTKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ ALTKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ ALTKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[5]} },
	{ ALTKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[6]} },
	{ ALTKEY,                       XK_y,      setlayout,      {.v = &layouts[7]} },
	{ ALTKEY,                       XK_space,  setlayout,      {0} },
	{ ALTKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ ALTKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ ALTKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ ALTKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ ALTKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ ALTKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ ALTKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ ALTKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ ALTKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ ALTKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ ALTKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkRootWin,			0,				Button3,		spawn,			{.v = menucmd } },
	{ ClkClientWin,			ShiftMask,		Button3,		spawn,			{.v = menucmd } },
	{ ClkClientWin,         ALTKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         ALTKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         ALTKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            ALTKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            ALTKEY,         Button3,        toggletag,      {0} },
};

