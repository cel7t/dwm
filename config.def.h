/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 1;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const int scalepreview            = 4;        /* Tag preview scaling */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = -1;
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */

/* The format in which the tag is written when named. E.g. %d: %.12s will write the tag number
 * followed the first 12 characters of the given string. You can also just use "%d: %s" here. */
#define NAMETAG_FORMAT "%d: %.12s"
/* The maximum amount of bytes reserved for each tag text. */
#define MAX_TAGLEN 16
/* The command to run (via popen). This can be tailored by adding a prompt, passing other command
 * line arguments or providing name options. Optionally you can use other dmenu like alternatives
 * like rofi -dmenu. */
#define NAMETAG_COMMAND "dmenu < /dev/null"

/* alt-tab configuration */
static const unsigned int tabmodkey        = 0x40; /* (Alt) when this key is held down the alt-tab functionality stays active. Must be the same modifier as used to run alttabstart */
static const unsigned int tabcyclekey      = 0x17; /* (Tab) when this key is hit the menu moves one position forward in client stack. Must be the same key as used to run alttabstart */
static const unsigned int tabposy          = 1;    /* tab position on Y axis, 0 = top, 1 = center, 2 = bottom */
static const unsigned int tabposx          = 1;    /* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxwtab          = 600;  /* tab menu width */
static const unsigned int maxhtab          = 200;  /* tab menu height */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static void (*bartabmonfns[])(Monitor *) = { monocle /* , customlayoutfn */ };
static const char *fonts[]               = { "Terminus:style=Bold:size=12", "Noto Color Emoji:pixelsize=16"};
static const char dmenufont[]            = "Terminus:style=Bold:size=12";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#fefefe";
static char normbgcolor[]                = "#120f14";
static char normbordercolor[]            = "#aa7ca4";
static char normfloatcolor[]             = "#346fb1";

static char selfgcolor[]                 = "#2a2a2a";
static char selbgcolor[]                 = "#dfaf6d";
static char selbordercolor[]             = "#A68972";
static char selfloatcolor[]              = "#dfaf6d";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#346fb1";

static char titleselfgcolor[]            = "#222222";
static char titleselbgcolor[]            = "#dfaf6d";
static char titleselbordercolor[]        = "#dfaf6d";
static char titleselfloatcolor[]         = "#dfaf6d";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#346fb1";

static char tagsselfgcolor[]             = "#222222";
static char tagsselbgcolor[]             = "#dfaf6d";
static char tagsselbordercolor[]         = "#dfaf6d";
static char tagsselfloatcolor[]          = "#dfaf6d";

static char hidnormfgcolor[]             = "#dfaf6d";
static char hidselfgcolor[]              = "#6a99cd";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#346fb1";




static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};





/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char tagicons[][NUMTAGS][MAX_TAGLEN] =
{
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* grid of tags */
#define SWITCHTAG_UP                1 << 0
#define SWITCHTAG_DOWN              1 << 1
#define SWITCHTAG_LEFT              1 << 2
#define SWITCHTAG_RIGHT             1 << 3
#define SWITCHTAG_TOGGLETAG         1 << 4
#define SWITCHTAG_TAG               1 << 5
#define SWITCHTAG_VIEW              1 << 6
#define SWITCHTAG_TOGGLEVIEW        1 << 7

static const int tagrows = 2;

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
  RULE(.class = "QJackCtl", .isfloating = 1)
  RULE(.class = "GIMP", .isfloating = 1)
  RULE(.class = "mpv", .isfloating = 1)
  RULE(.class = "Tor Browser", .isfloating = 1)
  RULE(.title = "dclock", .isfloating = 1)
  RULE(.class = "st", .isterminal = 1)
  RULE(.class = "URxvt", .isterminal = 1)
  RULE(.class = "XTerm", .isterminal = 1)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	 { -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	 { -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	 { -1,        0,     BAR_ALIGN_LEFT,   width_taggrid,            draw_taggrid,           click_taggrid,           NULL,                    "taggrid" },
	 { statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,           draw_status2d,          click_statuscmd,         NULL,                    "status2d" },
	 {  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	 { -1,        0,     BAR_ALIGN_NONE,   width_bartabgroups,       draw_bartabgroups,      click_bartabgroups,      NULL,                    "bartabgroups" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int nstack      = 0;    /* number of clients in primary stack area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define BARTAB_BORDERS 0       // 0 = off, 1 = on

static const Layout layouts[] = {
	/* symbol     arrange function, { nmaster, nstack, layout, master axis, stack axis, secondary stack axis, symbol func } */
	{ "[]=",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, // default tile layout
 	{ "><>",      NULL,             {0} },    /* no layout function means floating behavior */
	{ "[M]",      flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, monoclesymbols } }, // monocle
	{ "|||",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // columns (col) layout
	{ ">M>",      flextile,         { -1, -1, FLOATING_MASTER, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // floating master
	{ "[D]",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, MONOCLE, 0, NULL } }, // deck
	{ "TTT",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // bstack
	{ "===",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // bstackhoriz
	{ "|M|",      flextile,         { -1, -1, SPLIT_CENTERED_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, TOP_TO_BOTTOM, NULL } }, // centeredmaster
	{ "-M-",      flextile,         { -1, -1, SPLIT_CENTERED_HORIZONTAL, TOP_TO_BOTTOM, LEFT_TO_RIGHT, LEFT_TO_RIGHT, NULL } }, // centeredmaster horiz
	{ ":::",      flextile,         { -1, -1, NO_SPLIT, GAPPLESSGRID, GAPPLESSGRID, 0, NULL } }, // gappless grid
	{ "[\\]",     flextile,         { -1, -1, NO_SPLIT, DWINDLE, DWINDLE, 0, NULL } }, // fibonacci dwindle
	{ "(@)",      flextile,         { -1, -1, NO_SPLIT, SPIRAL, SPIRAL, 0, NULL } }, // fibonacci spiral
	{ "[T]",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TATAMI, 0, NULL } }, // tatami mats
	{ "[]=",      tile,             {0} },
	{ "[M]",      monocle,          {0} },
	{ "HHH",      grid,             {0} },
	{ ":::",      gaplessgrid,      {0} },
};


/* key definitions */
#define MODKEY Mod1Mask
#define SUPKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};

static const char *roficmd[] = { "rofi", "-show", "combi", NULL };
static const char *rofiecmd[] = { "rofi", "-modi", "emoji", "-show", "emoji", NULL };
static const char *jgmenucmd[] = { "jgmenu_run", NULL };
static const char *lockcmd[] = { "betterlockscreen", "-l", NULL };
static const char *termbcmd[]  = { "xterm", NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *termacmd[]  = { "st", NULL };
static const char *browscmd[]  = { "librewolf", NULL };
static const char *emacscmd[]  = { "emacsclient", "-c", "-s", "/home/sixtyfour/.emacs.d/server/server", NULL };
static const char *dolphincmd[]  = { "dolphin", NULL };
// static const char *incvol[] = {"wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "5%+", NULL};
// static const char *decvol[] = {"wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "5%-", NULL};
// static const char *mutecmd[] = {"wpctl", "set-mute", "@DEFAULT_AUDIO_SINK@", "toggle", NULL};
static const char *incvol[] = {"vol", "-u", NULL};
static const char *decvol[] = {"vol", "-d", NULL};
static const char *mutecmd[] = {"vol", "-m", NULL};
static const char *lightucmd[]  = { "light", "-A", "5", NULL };
static const char *lightdcmd[]  = { "light", "-U", "5", NULL };
static const char *screenshotcmd[]  = { "flameshot", "gui", NULL };

/* commands spawned when clicking statusbar, the mouse button pressed is exported as BUTTON */
static const StatusCmd statuscmds[] = {
	{ "notify-send Volume$BUTTON", 1 },
	{ "notify-send CPU$BUTTON", 2 },
	{ "notify-send Battery$BUTTON", 3 },
};
/* test the above with: xsetroot -name "$(printf '\x01Volume |\x02 CPU |\x03 Battery')" */
static const char *statuscmd[] = { "/bin/sh", "-c", NULL, NULL };


static const Key keys[] = {
	/* modifier                     key            function                argument */

	{ SUPKEY,                       XK_Escape,     setkeymode,             {.ui = COMMANDMODE} },
  { SUPKEY|ShiftMask,             XK_l,          spawn,                  {.v = lockcmd } },
  { MODKEY|ShiftMask,             XK_p,          spawn,                  {.v = dmenucmd } },
  { MODKEY|ShiftMask,             XK_s,          spawn,                  {.v = screenshotcmd } },
  { SUPKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
  { MODKEY,                       XK_p,          spawn,                  {.v = roficmd } },
  { SUPKEY,                       XK_period,     spawn,                  {.v = rofiecmd } },
  { MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termcmd } },
  { SUPKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termbcmd } },
  { MODKEY|SUPKEY|ShiftMask,      XK_Return,     spawn,                  {.v = termacmd } },
	{ MODKEY|ControlMask,           XK_c,	         spawn,                  {.v = browscmd } },
	{ MODKEY|ControlMask,           XK_e,	         spawn,                  {.v = emacscmd } },
	{ MODKEY|ControlMask,           XK_d,	         spawn,                  {.v = dolphincmd } },
	{ 0,				                   0x1008ff11,	   spawn,				           {.v = decvol } },
	{ 0,				                   0x1008ff13,	   spawn,				           {.v = incvol } },
	{ 0,				                   0x1008ff12,		 spawn,				           {.v = mutecmd } },
	{ 0,				                   0x1008ff15,		 spawn,				           {.v = mutecmd } },
	{ MODKEY,		                   0x1008ff13,	   spawn,					         {.v = lightucmd } },
	{ MODKEY,		                   0x1008ff11,	   spawn,					         {.v = lightdcmd } },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY|ControlMask,           XK_i,          incnstack,              {.i = +1 } },
	{ MODKEY|ControlMask,           XK_u,          incnstack,              {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ SUPKEY,                       XK_Down,       moveresize,             {.v = "0x 25y 0w 0h" } },
	{ SUPKEY,                       XK_Up,         moveresize,             {.v = "0x -25y 0w 0h" } },
	{ SUPKEY,                       XK_Right,      moveresize,             {.v = "25x 0y 0w 0h" } },
	{ SUPKEY,                       XK_Left,       moveresize,             {.v = "-25x 0y 0w 0h" } },
	{ SUPKEY|ShiftMask,             XK_Down,       moveresize,             {.v = "0x 0y 0w 25h" } },
	{ SUPKEY|ShiftMask,             XK_Up,         moveresize,             {.v = "0x 0y 0w -25h" } },
	{ SUPKEY|ShiftMask,             XK_Right,      moveresize,             {.v = "0x 0y 25w 0h" } },
	{ SUPKEY|ShiftMask,             XK_Left,       moveresize,             {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ShiftMask,             XK_j,          movestack,              {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,          movestack,              {.i = -1 } },
	{ SUPKEY,                       XK_Return,     zoom,                   {0} },
	{ MODKEY|Mod4Mask,              XK_u,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },
	{ MODKEY,                       XK_Tab,        alttabstart,            {0} },
	{ MODKEY|ControlMask,           XK_z,          showhideclient,         {0} },
	{ MODKEY|ShiftMask,             XK_c,          killclient,             {0} },
	{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	{ MODKEY|ShiftMask,             XK_F2,         xrdb,                   {.v = NULL } },
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	{ MODKEY|ControlMask,           XK_t,          rotatelayoutaxis,       {.i = +1 } },   /* flextile, 1 = layout axis */
	{ MODKEY|ControlMask,           XK_Tab,        rotatelayoutaxis,       {.i = +2 } },   /* flextile, 2 = master axis */
	{ MODKEY|ControlMask|ShiftMask, XK_Tab,        rotatelayoutaxis,       {.i = +3 } },   /* flextile, 3 = stack axis */
	{ MODKEY|ControlMask|SUPKEY,  XK_Tab,        rotatelayoutaxis,       {.i = +4 } },   /* flextile, 4 = secondary stack axis */
	{ MODKEY|SUPKEY,              XK_t,          rotatelayoutaxis,       {.i = -1 } },   /* flextile, 1 = layout axis */
	{ MODKEY|SUPKEY,              XK_Tab,        rotatelayoutaxis,       {.i = -2 } },   /* flextile, 2 = master axis */
	{ MODKEY|SUPKEY|ShiftMask,    XK_Tab,        rotatelayoutaxis,       {.i = -3 } },   /* flextile, 3 = stack axis */
	{ MODKEY|SUPKEY|ShiftMask|ControlMask,     XK_Tab,        rotatelayoutaxis,       {.i = -4 } },   /* flextile, 4 = secondary stack axis */
	{ MODKEY|ControlMask,           XK_Return,     mirrorlayout,           {0} },          /* flextile, flip master and stack areas */
	{ MODKEY,                       XK_space,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY|ShiftMask,             XK_f,          togglefullscreen,       {0} },
	{ MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_n,          nametag,                {0} },
	{ MODKEY|ControlMask,           XK_Up,         switchtag,              { .ui = SWITCHTAG_UP    | SWITCHTAG_VIEW } },
	{ MODKEY|ControlMask,           XK_Down,       switchtag,              { .ui = SWITCHTAG_DOWN  | SWITCHTAG_VIEW } },
	{ MODKEY|ControlMask,           XK_Right,      switchtag,              { .ui = SWITCHTAG_RIGHT | SWITCHTAG_VIEW } },
	{ MODKEY|ControlMask,           XK_Left,       switchtag,              { .ui = SWITCHTAG_LEFT  | SWITCHTAG_VIEW } },
	{ MODKEY|SUPKEY,                XK_Up,         switchtag,              { .ui = SWITCHTAG_UP    | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
	{ MODKEY|SUPKEY,              XK_Down,       switchtag,              { .ui = SWITCHTAG_DOWN  | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
	{ MODKEY|SUPKEY,              XK_Right,      switchtag,              { .ui = SWITCHTAG_RIGHT | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
	{ MODKEY|SUPKEY,              XK_Left,       switchtag,              { .ui = SWITCHTAG_LEFT  | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};

static const Key cmdkeys[] = {
	/* modifier                    keys                     function         argument */
	{ 0,                           XK_Escape,               clearcmd,        {0} },
	{ ControlMask,                 XK_c,                    clearcmd,        {0} },
	{ 0,                           XK_i,                    setkeymode,      {.ui = INSERTMODE} },
};

static const Command commands[] = {
	/* modifier (4 keys)                          keysyms (4 keys)                                function         argument */
//	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_h,     0,         0},            setlayout,       {.v = &layouts[0]} },
//	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_o,     0,         0},            setlayout,       {.v = &layouts[2]} },
//	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_o,     0,         0},            onlyclient,      {0} },
//	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_v,     0,         0},            setlayout,       {.v = &layouts[0]} },
//	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_less,  0,         0},            setmfact,        {.f = -0.05} },
//	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_less,  0,         0},            setmfact,        {.f = +0.05} },
//	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_0,     0,         0},            setmfact,        {.f = +1.50} },
//	{ {ShiftMask,   0,          0,         0},    {XK_period, XK_e,     0,         0},            spawn,           {.v = dmenucmd} },
//	{ {ShiftMask,   0,          0,         0},    {XK_period, XK_o,     0,         0},            spawn,           {.v = dmenucmd} },
//	{ {ShiftMask,   0,          0,         0},    {XK_period, XK_q,     XK_Return, 0},            quit,            {0} },
//	{ {ShiftMask,   0,          0,         0},    {XK_period, XK_b,     XK_d,      XK_Return},    killclient,      {0} },
//	{ {ShiftMask,   0,          0,         0},    {XK_period, XK_b,     XK_n,      XK_Return},    focusstack,      {.i = +1} },
//	{ {ShiftMask,   0,          ShiftMask, 0},    {XK_period, XK_b,     XK_n,      XK_Return},    focusstack,      {.i = -1} },
	{ {0,           0,          0,         0},    {XK_Return, 0,     0,     0},    spawn,            {.v = termcmd} },
	{ {0,           0,          0,         0},    {XK_Return, 0,     0,     0},    spawn,            {.v = termcmd} },
	{ {0,           0,          0,         0},    {XK_p,      0,     0,     0},    spawn,            {.v = roficmd} },
	{ {0,           0,          0,         0},    {XK_e,      0,     0,     0},    spawn,            {.v = emacscmd} },
	{ {0,           0,          0,         0},    {XK_b,      0,     0,     0},    spawn,            {.v = browscmd} },
	{ {0,           0,          0,         0},    {XK_t,      0,     0,     0},    setlayout,        {.v = &layouts[0]} },
	{ {0,           0,          0,         0},    {XK_f,      0,     0,     0},    setlayout,        {.v = &layouts[1]} },
	{ {0,           0,          0,         0},    {XK_m,      0,     0,     0},    setlayout,        {.v = &layouts[2]} },
	{ {0,           0,          0,         0},    {XK_c,      XK_c,  0,     0},    killclient,             {0} },
	{ {0,           0,          0,         0},    {XK_Down,   0,     0,     0},    moveresize,       {.v = "0x 25y 0w 0h" } },
	{ {0,           0,          0,         0},    {XK_Up,     0,     0,     0},    moveresize,       {.v = "0x -25y 0w 0h" } },
	{ {0,           0,          0,         0},    {XK_Right,  0,     0,     0},    moveresize,       {.v = "25x 0y 0w 0h" } },
	{ {0,           0,          0,         0},    {XK_Left,   0,     0,     0},    moveresize,       {.v = "-25x 0y 0w 0h" } },
	{ {ShiftMask,   0,          0,         0},    {XK_Down,   0,     0,     0},    moveresize,       {.v = "0x 0y 0w 25h" } },
	{ {ShiftMask,   0,          0,         0},    {XK_Up,     0,     0,     0},    moveresize,       {.v = "0x 0y 0w -25h" } },
	{ {ShiftMask,   0,          0,         0},    {XK_Right,  0,     0,     0},    moveresize,       {.v = "0x 0y 25w 0h" } },
	{ {ShiftMask,   0,          0,         0},    {XK_Left,   0,     0,     0},    moveresize,       {.v = "0x 0y -25w 0h" } },
	{ {0,           0,          0,         0},    {XK_j,      0,     0,     0},    focusstack,             {.i = +1 } },
	{ {0,           0,          0,         0},    {XK_k,      0,     0,     0},    focusstack,             {.i = -1 } },
	{ {ShiftMask,   0,          0,         0},    {XK_j,      0,     0,     0},    movestack,              {.i = +1 } },
	{ {ShiftMask,   0,          0,         0},    {XK_k,      0,     0,     0},    movestack,              {.i = -1 } },
	{ {0,           0,          0,         0},    {XK_1,      0,     0,     0},    comboview,          {.ui = 1 << 0} },
	{ {0,           0,          0,         0},    {XK_2,      0,     0,     0},    comboview,          {.ui = 1 << 1} },
	{ {0,           0,          0,         0},    {XK_3,      0,     0,     0},    comboview,          {.ui = 1 << 2} },
	{ {0,           0,          0,         0},    {XK_4,      0,     0,     0},    comboview,          {.ui = 1 << 3} },
	{ {0,           0,          0,         0},    {XK_5,      0,     0,     0},    comboview,          {.ui = 1 << 4} },
	{ {0,           0,          0,         0},    {XK_6,      0,     0,     0},    comboview,          {.ui = 1 << 5} },
	{ {0,           0,          0,         0},    {XK_7,      0,     0,     0},    comboview,          {.ui = 1 << 6} },
	{ {0,           0,          0,         0},    {XK_8,      0,     0,     0},    comboview,          {.ui = 1 << 7} },
	{ {0,           0,          0,         0},    {XK_9,      0,     0,     0},    comboview,          {.ui = 1 << 8} },
	{ {ShiftMask,   0,          0,         0},    {XK_1,      0,     0,     0},    combotag,           {.ui = 1 << 0} },
	{ {ShiftMask,   0,          0,         0},    {XK_2,      0,     0,     0},    combotag,           {.ui = 1 << 1} },
	{ {ShiftMask,   0,          0,         0},    {XK_3,      0,     0,     0},    combotag,           {.ui = 1 << 2} },
	{ {ShiftMask,   0,          0,         0},    {XK_4,      0,     0,     0},    combotag,           {.ui = 1 << 3} },
	{ {ShiftMask,   0,          0,         0},    {XK_5,      0,     0,     0},    combotag,           {.ui = 1 << 4} },
	{ {ShiftMask,   0,          0,         0},    {XK_6,      0,     0,     0},    combotag,           {.ui = 1 << 5} },
	{ {ShiftMask,   0,          0,         0},    {XK_7,      0,     0,     0},    combotag,           {.ui = 1 << 6} },
	{ {ShiftMask,   0,          0,         0},    {XK_8,      0,     0,     0},    combotag,           {.ui = 1 << 7} },
	{ {ShiftMask,   0,          0,         0},    {XK_9,      0,     0,     0},    combotag,           {.ui = 1 << 8} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button1,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,                   Button3,        spawn,          {.v = statuscmd } },
	{ ClkRootWin,           0,                   Button3,        spawn,          {.v = jgmenucmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};


