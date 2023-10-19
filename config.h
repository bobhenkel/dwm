/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=15" };
static const char dmenufont[]       = "monospace:size=15";
static const char col_gray1[]       = "#232a2d"; //"#222222"; //Status bar background color on the far right of bar
static const char col_gray2[]       = "#232a2d"; //"#444444";
static const char col_gray3[]       = "#bbbbbb"; //Tag bar text
static const char col_gray4[]       = "#de7625"; //"#eeeeee"; //Bar window text color
static const char col_cyan[]        = "#1d70b1";  //"#005577"; // Bar center background color
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class&((Keychord){1, {{MODKEY|ShiftMask, XK_j}},
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isTerminal   noswallow monitor */
	{ "Gimp",    NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "st-256color",      NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
       &((Keychord){1, {{MODKEY, KEY}},                         view,           {.ui = 1 << TAG} }), \
       &((Keychord){1, {{MODKEY|ControlMask, KEY}},             toggleview,     {.ui = 1 << TAG} }), \
       &((Keychord){1, {{MODKEY|ShiftMask, KEY}},               tag,            {.ui = 1 << TAG} }), \
       &((Keychord){1, {{MODKEY|ControlMask|ShiftMask, KEY}},   toggletag,      {.ui = 1 << TAG} }),

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

//static const Key keys[] = {
	/* modifier                     key        function        argument */
static Keychord *keychords[] = {
       /* Keys        function        argument */
       &((Keychord){1, {{MODKEY, XK_p}},                                       spawn,          {.v = dmenucmd } }),
       &((Keychord){1, {{MODKEY|ShiftMask, XK_Return}},                        spawn,          {.v = termcmd } }),
       &((Keychord){2, {{MODKEY, XK_e}, {MODKEY, XK_e}},                       spawn,          {.v = termcmd } }),
       &((Keychord){1, {{MODKEY, XK_b}},                                       togglebar,      {0} }),
       &((Keychord){1, {{MODKEY|ShiftMask, XK_j}},                             rotatestack,    {.i = +1 } }),
       &((Keychord){1, {{MODKEY|ShiftMask, XK_k}},                             rotatestack,    {.i = -1 } }),
       &((Keychord){1, {{MODKEY, XK_j}},                                       focusstack,     {.i = +1 } }),
       &((Keychord){1, {{MODKEY, XK_k}},                                       focusstack,     {.i = -1 } }),
       &((Keychord){1, {{MODKEY, XK_i}},                                       incnmaster,     {.i = +1 } }),
       &((Keychord){1, {{MODKEY, XK_d}},                                       incnmaster,     {.i = -1 } }),
       &((Keychord){1, {{MODKEY, XK_h}},                                       setmfact,       {.f = -0.05} }),
       &((Keychord){1, {{MODKEY, XK_l}},                                       setmfact,       {.f = +0.05} }),
       &((Keychord){1, {{MODKEY, XK_Return}},                                  zoom,           {0} }),
       &((Keychord){1, {{MODKEY, XK_Tab}},                                     view,           {0} }),
       &((Keychord){1, {{MODKEY|ShiftMask, XK_c}},                             killclient,     {0} }),
       &((Keychord){1, {{MODKEY, XK_t}},                                       setlayout,      {.v = &layouts[0]} }),
       &((Keychord){1, {{MODKEY, XK_f}},                                       setlayout,      {.v = &layouts[1]} }),
       &((Keychord){1, {{MODKEY, XK_m}},                                       setlayout,      {.v = &layouts[2]} }),
       &((Keychord){1, {{MODKEY, XK_space}},                                   setlayout,      {0} }),
       &((Keychord){1, {{MODKEY|ShiftMask, XK_space}},                         togglefloating, {0} }),
       &((Keychord){1, {{MODKEY, XK_0}},                                       view,           {.ui = ~0 } }),
       &((Keychord){1, {{MODKEY|ShiftMask, XK_0}},                             tag,            {.ui = ~0 } }),
       &((Keychord){1, {{MODKEY, XK_comma}},                                   focusmon,       {.i = -1 } }),
       &((Keychord){1, {{MODKEY, XK_period}},                                  focusmon,       {.i = +1 } }),
       &((Keychord){1, {{MODKEY|ShiftMask, XK_comma}},                         tagmon,         {.i = -1 } }),
       &((Keychord){1, {{MODKEY|ShiftMask, XK_period}},                        tagmon,         {.i = +1 } }),
       &((Keychord){1, {{MODKEY|ShiftMask, XK_q}},                             quit,           {0} }), 
       &((Keychord){1, {{MODKEY|ShiftMask, XK_r}},                             quit,           {1} }),
       &((Keychord){2, {{MODKEY, XK_a}, {0, XK_a}},                            spawn,          SHCMD("alacritty") }),
       &((Keychord){3, {{MODKEY, XK_a}, {0, XK_1}, {0, XK_0}}, view, {.ui = 1 << 9 }}),  // For tag "10"
       &((Keychord){3, {{MODKEY, XK_a}, {0, XK_1}, {0, XK_1}}, view, {.ui = 1 << 10}}),  // For tag "11"
       &((Keychord){3, {{MODKEY, XK_a}, {0, XK_1}, {0, XK_2}}, view, {.ui = 1 << 11}}),  // For tag "12"
       &((Keychord){3, {{MODKEY, XK_w}, {0, XK_1}, {0, XK_2}}, tag, {.ui = 1 << 11 }}),  // Move window to tag "12"
       TAGKEYS(                        XK_1,                      0)
       TAGKEYS(                        XK_2,                      1)
       TAGKEYS(                        XK_3,                      2)
       TAGKEYS(                        XK_4,                      3)
       TAGKEYS(                        XK_5,                      4)
       TAGKEYS(                        XK_6,                      5)
       TAGKEYS(                        XK_7,                      6)
       TAGKEYS(                        XK_8,                      7)
       TAGKEYS(                        XK_9,                      8)
       //TAGKEYS(                        &((Keychord){2, {{MODKEY, XK_a}, {XK_1, XK_0}}), 9)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
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

