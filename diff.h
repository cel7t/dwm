8c8
< static const unsigned int gappih         = 20;  /* horiz inner gap between windows */
---
> static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
11c11
< static const unsigned int gappov         = 30;  /* vert outer gap between windows and screen edge */
---
> static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
16c16
< static const int statusmon               = 'A';
---
> static const int statusmon               = -1;
42,44c42,43
< static void (*bartabmonfns[])(Monitor *) = { monocle /* , customlayoutfn */ };
< static const char *fonts[]               = { "monospace:size=10" };
< static const char dmenufont[]            = "monospace:size=10";
---
> static const char *fonts[]               = { "Terminus:style=Bold:size=12", "Noto Color Emoji:pixelsize=16"};
> static const char dmenufont[]            = "Terminus:style=Bold:size=12";
48,56c47,55
< static char normfgcolor[]                = "#bbbbbb";
< static char normbgcolor[]                = "#222222";
< static char normbordercolor[]            = "#444444";
< static char normfloatcolor[]             = "#db8fd9";
< 
< static char selfgcolor[]                 = "#eeeeee";
< static char selbgcolor[]                 = "#005577";
< static char selbordercolor[]             = "#005577";
< static char selfloatcolor[]              = "#005577";
---
> static char normfgcolor[]                = "#fefefe";
> static char normbgcolor[]                = "#120f14";
> static char normbordercolor[]            = "#aa7ca4";
> static char normfloatcolor[]             = "#346fb1";
> 
> static char selfgcolor[]                 = "#2a2a2a";
> static char selbgcolor[]                 = "#dfaf6d";
> static char selbordercolor[]             = "#A68972";
> static char selfloatcolor[]              = "#dfaf6d";
61c60
< static char titlenormfloatcolor[]        = "#db8fd9";
---
> static char titlenormfloatcolor[]        = "#346fb1";
63,66c62,65
< static char titleselfgcolor[]            = "#eeeeee";
< static char titleselbgcolor[]            = "#005577";
< static char titleselbordercolor[]        = "#005577";
< static char titleselfloatcolor[]         = "#005577";
---
> static char titleselfgcolor[]            = "#222222";
> static char titleselbgcolor[]            = "#dfaf6d";
> static char titleselbordercolor[]        = "#dfaf6d";
> static char titleselfloatcolor[]         = "#dfaf6d";
71c70
< static char tagsnormfloatcolor[]         = "#db8fd9";
---
> static char tagsnormfloatcolor[]         = "#346fb1";
73,76c72,75
< static char tagsselfgcolor[]             = "#eeeeee";
< static char tagsselbgcolor[]             = "#005577";
< static char tagsselbordercolor[]         = "#005577";
< static char tagsselfloatcolor[]          = "#005577";
---
> static char tagsselfgcolor[]             = "#222222";
> static char tagsselbgcolor[]             = "#dfaf6d";
> static char tagsselbordercolor[]         = "#dfaf6d";
> static char tagsselfloatcolor[]          = "#dfaf6d";
78,79c77,78
< static char hidnormfgcolor[]             = "#005577";
< static char hidselfgcolor[]              = "#227799";
---
> static char hidnormfgcolor[]             = "#dfaf6d";
> static char hidselfgcolor[]              = "#6a99cd";
86c85
< static char urgfloatcolor[]              = "#db8fd9";
---
> static char urgfloatcolor[]              = "#346fb1";
142,152d140
< /* grid of tags */
< #define SWITCHTAG_UP                1 << 0
< #define SWITCHTAG_DOWN              1 << 1
< #define SWITCHTAG_LEFT              1 << 2
< #define SWITCHTAG_RIGHT             1 << 3
< #define SWITCHTAG_TOGGLETAG         1 << 4
< #define SWITCHTAG_TAG               1 << 5
< #define SWITCHTAG_VIEW              1 << 6
< #define SWITCHTAG_TOGGLEVIEW        1 << 7
< 
< static const int tagrows = 2;
183,184c171,177
< 	RULE(.class = "Gimp", .tags = 1 << 4)
< 	RULE(.class = "Firefox", .tags = 1 << 7)
---
>   RULE(.class = "QJackCtl", .isfloating = 1)
>   RULE(.class = "GIMP", .isfloating = 1)
>   RULE(.class = "mpv", .isfloating = 1)
>   RULE(.class = "Tor Browser", .isfloating = 1)
>   RULE(.title = "dclock", .isfloating = 1)
>   RULE(.class = "URxvt", .isterminal = 1)
>   RULE(.class = "XTerm", .isterminal = 1)
204,206d196
< 	{ -1,        0,     BAR_ALIGN_LEFT,   width_taggrid,            draw_taggrid,           click_taggrid,           NULL,                    "taggrid" },
< 	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
< 	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
208c198,200
< 	{ -1,        0,     BAR_ALIGN_NONE,   width_bartabgroups,       draw_bartabgroups,      click_bartabgroups,      NULL,                    "bartabgroups" },
---
> 	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
> 	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
> 	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
224c216
< 	{ "[M]",      flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, monoclesymbols } }, // monocle
---
> 	{ "[M]",      flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, NULL } }, // monocle
244a237
> #define SUPKEY Mod4Mask
268c261,279
< static const char *termcmd[]  = { "st", NULL };
---
> 
> static const char *roficmd[] = { "rofi", "-show", "combi", NULL };
> static const char *rofiecmd[] = { "rofi", "-modi", "emoji", "-show", "emoji", NULL };
> static const char *jgmenucmd[] = { "jgmenu_run", NULL };
> static const char *lockcmd[] = { "betterlockscreen", "-l", NULL };
> static const char *termbcmd[]  = { "xterm", NULL };
> static const char *termcmd[]  = { "urxvt", NULL };
> static const char *browscmd[]  = { "librewolf", NULL };
> static const char *emacscmd[]  = { "emacsclient", "-c", "-s", "/home/sixtyfour/.emacs.d/server/server", NULL };
> static const char *dolphincmd[]  = { "dolphin", NULL };
> // static const char *incvol[] = {"wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "5%+", NULL};
> // static const char *decvol[] = {"wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "5%-", NULL};
> // static const char *mutecmd[] = {"wpctl", "set-mute", "@DEFAULT_AUDIO_SINK@", "toggle", NULL};
> static const char *incvol[] = {"vol", "-u", NULL};
> static const char *decvol[] = {"vol", "-d", NULL};
> static const char *mutecmd[] = {"vol", "-m", NULL};
> static const char *lightucmd[]  = { "light", "-A", "5", NULL };
> static const char *lightdcmd[]  = { "light", "-U", "5", NULL };
> static const char *screenshotcmd[]  = { "flameshot", "gui", NULL };
282,283c293,310
< 	{ MODKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
< 	{ MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termcmd } },
---
> 
>   { SUPKEY|ShiftMask,             XK_l,          spawn,                  {.v = lockcmd } },
>   { MODKEY|ShiftMask,             XK_p,          spawn,                  {.v = dmenucmd } },
>   { MODKEY|ShiftMask,             XK_s,          spawn,                  {.v = screenshotcmd } },
>   { SUPKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
>   { MODKEY,                       XK_p,          spawn,                  {.v = roficmd } },
>   { SUPKEY,                       XK_period,     spawn,                  {.v = rofiecmd } },
>   { MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termcmd } },
>   { SUPKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termbcmd } },
> 	{ MODKEY|ControlMask,           XK_c,	         spawn,                  {.v = browscmd } },
> 	{ MODKEY|ControlMask,           XK_e,	         spawn,                  {.v = emacscmd } },
> 	{ MODKEY|ControlMask,           XK_d,	         spawn,                  {.v = dolphincmd } },
> 	{ 0,				                   0x1008ff11,	   spawn,				           {.v = decvol } },
> 	{ 0,				                   0x1008ff13,	   spawn,				           {.v = incvol } },
> 	{ 0,				                   0x1008ff12,		 spawn,				           {.v = mutecmd } },
> 	{ 0,				                   0x1008ff15,		 spawn,				           {.v = mutecmd } },
> 	{ MODKEY,		                   0x1008ff13,	   spawn,					         {.v = lightucmd } },
> 	{ MODKEY,		                   0x1008ff11,	   spawn,					         {.v = lightdcmd } },
293,300c320,327
< 	{ MODKEY|Mod4Mask,              XK_Down,       moveresize,             {.v = "0x 25y 0w 0h" } },
< 	{ MODKEY|Mod4Mask,              XK_Up,         moveresize,             {.v = "0x -25y 0w 0h" } },
< 	{ MODKEY|Mod4Mask,              XK_Right,      moveresize,             {.v = "25x 0y 0w 0h" } },
< 	{ MODKEY|Mod4Mask,              XK_Left,       moveresize,             {.v = "-25x 0y 0w 0h" } },
< 	{ MODKEY|Mod4Mask|ShiftMask,    XK_Down,       moveresize,             {.v = "0x 0y 0w 25h" } },
< 	{ MODKEY|Mod4Mask|ShiftMask,    XK_Up,         moveresize,             {.v = "0x 0y 0w -25h" } },
< 	{ MODKEY|Mod4Mask|ShiftMask,    XK_Right,      moveresize,             {.v = "0x 0y 25w 0h" } },
< 	{ MODKEY|Mod4Mask|ShiftMask,    XK_Left,       moveresize,             {.v = "0x 0y -25w 0h" } },
---
> 	{ SUPKEY,                       XK_Down,       moveresize,             {.v = "0x 25y 0w 0h" } },
> 	{ SUPKEY,                       XK_Up,         moveresize,             {.v = "0x -25y 0w 0h" } },
> 	{ SUPKEY,                       XK_Right,      moveresize,             {.v = "25x 0y 0w 0h" } },
> 	{ SUPKEY,                       XK_Left,       moveresize,             {.v = "-25x 0y 0w 0h" } },
> 	{ SUPKEY|ShiftMask,             XK_Down,       moveresize,             {.v = "0x 0y 0w 25h" } },
> 	{ SUPKEY|ShiftMask,             XK_Up,         moveresize,             {.v = "0x 0y 0w -25h" } },
> 	{ SUPKEY|ShiftMask,             XK_Right,      moveresize,             {.v = "0x 0y 25w 0h" } },
> 	{ SUPKEY|ShiftMask,             XK_Left,       moveresize,             {.v = "0x 0y -25w 0h" } },
303c330
< 	{ MODKEY,                       XK_Return,     zoom,                   {0} },
---
> 	{ SUPKEY,                       XK_Return,     zoom,                   {0} },
321d347
< 	{ MODKEY|ControlMask,           XK_z,          showhideclient,         {0} },
324c350
< 	{ MODKEY|ShiftMask,             XK_F5,         xrdb,                   {.v = NULL } },
---
> 	{ MODKEY|ShiftMask,             XK_F2,         xrdb,                   {.v = NULL } },
331,335c357,361
< 	{ MODKEY|ControlMask|Mod1Mask,  XK_Tab,        rotatelayoutaxis,       {.i = +4 } },   /* flextile, 4 = secondary stack axis */
< 	{ MODKEY|Mod5Mask,              XK_t,          rotatelayoutaxis,       {.i = -1 } },   /* flextile, 1 = layout axis */
< 	{ MODKEY|Mod5Mask,              XK_Tab,        rotatelayoutaxis,       {.i = -2 } },   /* flextile, 2 = master axis */
< 	{ MODKEY|Mod5Mask|ShiftMask,    XK_Tab,        rotatelayoutaxis,       {.i = -3 } },   /* flextile, 3 = stack axis */
< 	{ MODKEY|Mod5Mask|Mod1Mask,     XK_Tab,        rotatelayoutaxis,       {.i = -4 } },   /* flextile, 4 = secondary stack axis */
---
> 	{ MODKEY|ControlMask|SUPKEY,  XK_Tab,        rotatelayoutaxis,       {.i = +4 } },   /* flextile, 4 = secondary stack axis */
> 	{ MODKEY|SUPKEY,              XK_t,          rotatelayoutaxis,       {.i = -1 } },   /* flextile, 1 = layout axis */
> 	{ MODKEY|SUPKEY,              XK_Tab,        rotatelayoutaxis,       {.i = -2 } },   /* flextile, 2 = master axis */
> 	{ MODKEY|SUPKEY|ShiftMask,    XK_Tab,        rotatelayoutaxis,       {.i = -3 } },   /* flextile, 3 = stack axis */
> 	{ MODKEY|SUPKEY|ShiftMask|ControlMask,     XK_Tab,        rotatelayoutaxis,       {.i = -4 } },   /* flextile, 4 = secondary stack axis */
339c365
< 	{ MODKEY,                       XK_y,          togglefullscreen,       {0} },
---
> 	{ MODKEY|ShiftMask,             XK_m,          fullscreen,             {0} },
347,354d372
< 	{ MODKEY|ControlMask,           XK_Up,         switchtag,              { .ui = SWITCHTAG_UP    | SWITCHTAG_VIEW } },
< 	{ MODKEY|ControlMask,           XK_Down,       switchtag,              { .ui = SWITCHTAG_DOWN  | SWITCHTAG_VIEW } },
< 	{ MODKEY|ControlMask,           XK_Right,      switchtag,              { .ui = SWITCHTAG_RIGHT | SWITCHTAG_VIEW } },
< 	{ MODKEY|ControlMask,           XK_Left,       switchtag,              { .ui = SWITCHTAG_LEFT  | SWITCHTAG_VIEW } },
< 	{ MODKEY|Mod4Mask,              XK_Up,         switchtag,              { .ui = SWITCHTAG_UP    | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
< 	{ MODKEY|Mod4Mask,              XK_Down,       switchtag,              { .ui = SWITCHTAG_DOWN  | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
< 	{ MODKEY|Mod4Mask,              XK_Right,      switchtag,              { .ui = SWITCHTAG_RIGHT | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
< 	{ MODKEY|Mod4Mask,              XK_Left,       switchtag,              { .ui = SWITCHTAG_LEFT  | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
373,374d390
< 	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
< 	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
378a395
> 	{ ClkRootWin,           0,                   Button3,        spawn,          {.v = jgmenucmd } },
