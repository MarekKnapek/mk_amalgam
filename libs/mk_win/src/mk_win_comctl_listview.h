#ifndef mk_include_guard_win_comctl_listview
#define mk_include_guard_win_comctl_listview


#include "mk_win_char.h"

#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include "../../mk_utils/src/mk_jumbo.h"


#define mk_win_comctl_listview_classname mk_win_char_c("SysListView32")

#define mk_win_comctl_listview_wm_first                    ((unsigned short int)(0x1000ul))
#define mk_win_comctl_listview_wm_getbkcolor               ((unsigned short int)(mk_win_comctl_listview_wm_first +   0ul))
#define mk_win_comctl_listview_wm_setbkcolor               ((unsigned short int)(mk_win_comctl_listview_wm_first +   1ul))
#define mk_win_comctl_listview_wm_getimagelist             ((unsigned short int)(mk_win_comctl_listview_wm_first +   2ul))
#define mk_win_comctl_listview_wm_setimagelist             ((unsigned short int)(mk_win_comctl_listview_wm_first +   3ul))
#define mk_win_comctl_listview_wm_getitemcount             ((unsigned short int)(mk_win_comctl_listview_wm_first +   4ul))
#define mk_win_comctl_listview_wm_getitema                 ((unsigned short int)(mk_win_comctl_listview_wm_first +   5ul))
#define mk_win_comctl_listview_wm_setitema                 ((unsigned short int)(mk_win_comctl_listview_wm_first +   6ul))
#define mk_win_comctl_listview_wm_insertitema              ((unsigned short int)(mk_win_comctl_listview_wm_first +   7ul))
#define mk_win_comctl_listview_wm_deleteitem               ((unsigned short int)(mk_win_comctl_listview_wm_first +   8ul))
#define mk_win_comctl_listview_wm_deleteallitems           ((unsigned short int)(mk_win_comctl_listview_wm_first +   9ul))
#define mk_win_comctl_listview_wm_getcallbackmask          ((unsigned short int)(mk_win_comctl_listview_wm_first +  10ul))
#define mk_win_comctl_listview_wm_setcallbackmask          ((unsigned short int)(mk_win_comctl_listview_wm_first +  11ul))
#define mk_win_comctl_listview_wm_getnextitem              ((unsigned short int)(mk_win_comctl_listview_wm_first +  12ul))
#define mk_win_comctl_listview_wm_finditema                ((unsigned short int)(mk_win_comctl_listview_wm_first +  13ul))
#define mk_win_comctl_listview_wm_getitemrect              ((unsigned short int)(mk_win_comctl_listview_wm_first +  14ul))
#define mk_win_comctl_listview_wm_setitemposition          ((unsigned short int)(mk_win_comctl_listview_wm_first +  15ul))
#define mk_win_comctl_listview_wm_getitemposition          ((unsigned short int)(mk_win_comctl_listview_wm_first +  16ul))
#define mk_win_comctl_listview_wm_getstringwidtha          ((unsigned short int)(mk_win_comctl_listview_wm_first +  17ul))
#define mk_win_comctl_listview_wm_hittest                  ((unsigned short int)(mk_win_comctl_listview_wm_first +  18ul))
#define mk_win_comctl_listview_wm_ensurevisible            ((unsigned short int)(mk_win_comctl_listview_wm_first +  19ul))
#define mk_win_comctl_listview_wm_scroll                   ((unsigned short int)(mk_win_comctl_listview_wm_first +  20ul))
#define mk_win_comctl_listview_wm_redrawitems              ((unsigned short int)(mk_win_comctl_listview_wm_first +  21ul))
#define mk_win_comctl_listview_wm_arrange                  ((unsigned short int)(mk_win_comctl_listview_wm_first +  22ul))
#define mk_win_comctl_listview_wm_editlabela               ((unsigned short int)(mk_win_comctl_listview_wm_first +  23ul))
#define mk_win_comctl_listview_wm_geteditcontrol           ((unsigned short int)(mk_win_comctl_listview_wm_first +  24ul))
#define mk_win_comctl_listview_wm_getcolumna               ((unsigned short int)(mk_win_comctl_listview_wm_first +  25ul))
#define mk_win_comctl_listview_wm_setcolumna               ((unsigned short int)(mk_win_comctl_listview_wm_first +  26ul))
#define mk_win_comctl_listview_wm_insertcolumna            ((unsigned short int)(mk_win_comctl_listview_wm_first +  27ul))
#define mk_win_comctl_listview_wm_deletecolumn             ((unsigned short int)(mk_win_comctl_listview_wm_first +  28ul))
#define mk_win_comctl_listview_wm_getcolumnwidth           ((unsigned short int)(mk_win_comctl_listview_wm_first +  29ul))
#define mk_win_comctl_listview_wm_setcolumnwidth           ((unsigned short int)(mk_win_comctl_listview_wm_first +  30ul))
#define mk_win_comctl_listview_wm_getheader                ((unsigned short int)(mk_win_comctl_listview_wm_first +  31ul))
#define mk_win_comctl_listview_wm_createdragimage          ((unsigned short int)(mk_win_comctl_listview_wm_first +  33ul))
#define mk_win_comctl_listview_wm_getviewrect              ((unsigned short int)(mk_win_comctl_listview_wm_first +  34ul))
#define mk_win_comctl_listview_wm_gettextcolor             ((unsigned short int)(mk_win_comctl_listview_wm_first +  35ul))
#define mk_win_comctl_listview_wm_settextcolor             ((unsigned short int)(mk_win_comctl_listview_wm_first +  36ul))
#define mk_win_comctl_listview_wm_gettextbkcolor           ((unsigned short int)(mk_win_comctl_listview_wm_first +  37ul))
#define mk_win_comctl_listview_wm_settextbkcolor           ((unsigned short int)(mk_win_comctl_listview_wm_first +  38ul))
#define mk_win_comctl_listview_wm_gettopindex              ((unsigned short int)(mk_win_comctl_listview_wm_first +  39ul))
#define mk_win_comctl_listview_wm_getcountperpage          ((unsigned short int)(mk_win_comctl_listview_wm_first +  40ul))
#define mk_win_comctl_listview_wm_getorigin                ((unsigned short int)(mk_win_comctl_listview_wm_first +  41ul))
#define mk_win_comctl_listview_wm_update                   ((unsigned short int)(mk_win_comctl_listview_wm_first +  42ul))
#define mk_win_comctl_listview_wm_setitemstate             ((unsigned short int)(mk_win_comctl_listview_wm_first +  43ul))
#define mk_win_comctl_listview_wm_getitemstate             ((unsigned short int)(mk_win_comctl_listview_wm_first +  44ul))
#define mk_win_comctl_listview_wm_getitemtexta             ((unsigned short int)(mk_win_comctl_listview_wm_first +  45ul))
#define mk_win_comctl_listview_wm_setitemtexta             ((unsigned short int)(mk_win_comctl_listview_wm_first +  46ul))
#define mk_win_comctl_listview_wm_setitemcount             ((unsigned short int)(mk_win_comctl_listview_wm_first +  47ul))
#define mk_win_comctl_listview_wm_sortitems                ((unsigned short int)(mk_win_comctl_listview_wm_first +  48ul))
#define mk_win_comctl_listview_wm_setitemposition32        ((unsigned short int)(mk_win_comctl_listview_wm_first +  49ul))
#define mk_win_comctl_listview_wm_getselectedcount         ((unsigned short int)(mk_win_comctl_listview_wm_first +  50ul))
#define mk_win_comctl_listview_wm_getitemspacing           ((unsigned short int)(mk_win_comctl_listview_wm_first +  51ul))
#define mk_win_comctl_listview_wm_getisearchstringa        ((unsigned short int)(mk_win_comctl_listview_wm_first +  52ul))
#define mk_win_comctl_listview_wm_seticonspacing           ((unsigned short int)(mk_win_comctl_listview_wm_first +  53ul))
#define mk_win_comctl_listview_wm_setextendedlistviewstyle ((unsigned short int)(mk_win_comctl_listview_wm_first +  54ul))
#define mk_win_comctl_listview_wm_getextendedlistviewstyle ((unsigned short int)(mk_win_comctl_listview_wm_first +  55ul))
#define mk_win_comctl_listview_wm_getsubitemrect           ((unsigned short int)(mk_win_comctl_listview_wm_first +  56ul))
#define mk_win_comctl_listview_wm_subitemhittest           ((unsigned short int)(mk_win_comctl_listview_wm_first +  57ul))
#define mk_win_comctl_listview_wm_setcolumnorderarray      ((unsigned short int)(mk_win_comctl_listview_wm_first +  58ul))
#define mk_win_comctl_listview_wm_getcolumnorderarray      ((unsigned short int)(mk_win_comctl_listview_wm_first +  59ul))
#define mk_win_comctl_listview_wm_sethotitem               ((unsigned short int)(mk_win_comctl_listview_wm_first +  60ul))
#define mk_win_comctl_listview_wm_gethotitem               ((unsigned short int)(mk_win_comctl_listview_wm_first +  61ul))
#define mk_win_comctl_listview_wm_sethotcursor             ((unsigned short int)(mk_win_comctl_listview_wm_first +  62ul))
#define mk_win_comctl_listview_wm_gethotcursor             ((unsigned short int)(mk_win_comctl_listview_wm_first +  63ul))
#define mk_win_comctl_listview_wm_approximateviewrect      ((unsigned short int)(mk_win_comctl_listview_wm_first +  64ul))
#define mk_win_comctl_listview_wm_setworkareas             ((unsigned short int)(mk_win_comctl_listview_wm_first +  65ul))
#define mk_win_comctl_listview_wm_getselectionmark         ((unsigned short int)(mk_win_comctl_listview_wm_first +  66ul))
#define mk_win_comctl_listview_wm_setselectionmark         ((unsigned short int)(mk_win_comctl_listview_wm_first +  67ul))
#define mk_win_comctl_listview_wm_setbkimagea              ((unsigned short int)(mk_win_comctl_listview_wm_first +  68ul))
#define mk_win_comctl_listview_wm_getbkimagea              ((unsigned short int)(mk_win_comctl_listview_wm_first +  69ul))
#define mk_win_comctl_listview_wm_getworkareas             ((unsigned short int)(mk_win_comctl_listview_wm_first +  70ul))
#define mk_win_comctl_listview_wm_sethovertime             ((unsigned short int)(mk_win_comctl_listview_wm_first +  71ul))
#define mk_win_comctl_listview_wm_gethovertime             ((unsigned short int)(mk_win_comctl_listview_wm_first +  72ul))
#define mk_win_comctl_listview_wm_getnumberofworkareas     ((unsigned short int)(mk_win_comctl_listview_wm_first +  73ul))
#define mk_win_comctl_listview_wm_settooltips              ((unsigned short int)(mk_win_comctl_listview_wm_first +  74ul))
#define mk_win_comctl_listview_wm_getitemw                 ((unsigned short int)(mk_win_comctl_listview_wm_first +  75ul))
#define mk_win_comctl_listview_wm_setitemw                 ((unsigned short int)(mk_win_comctl_listview_wm_first +  76ul))
#define mk_win_comctl_listview_wm_insertitemw              ((unsigned short int)(mk_win_comctl_listview_wm_first +  77ul))
#define mk_win_comctl_listview_wm_gettooltips              ((unsigned short int)(mk_win_comctl_listview_wm_first +  78ul))
#define mk_win_comctl_listview_wm_sortitemsex              ((unsigned short int)(mk_win_comctl_listview_wm_first +  81ul))
#define mk_win_comctl_listview_wm_finditemw                ((unsigned short int)(mk_win_comctl_listview_wm_first +  83ul))
#define mk_win_comctl_listview_wm_getstringwidthw          ((unsigned short int)(mk_win_comctl_listview_wm_first +  87ul))
#define mk_win_comctl_listview_wm_getgroupstate            ((unsigned short int)(mk_win_comctl_listview_wm_first +  92ul))
#define mk_win_comctl_listview_wm_getfocusedgroup          ((unsigned short int)(mk_win_comctl_listview_wm_first +  93ul))
#define mk_win_comctl_listview_wm_getcolumnw               ((unsigned short int)(mk_win_comctl_listview_wm_first +  95ul))
#define mk_win_comctl_listview_wm_setcolumnw               ((unsigned short int)(mk_win_comctl_listview_wm_first +  96ul))
#define mk_win_comctl_listview_wm_insertcolumnw            ((unsigned short int)(mk_win_comctl_listview_wm_first +  97ul))
#define mk_win_comctl_listview_wm_getgrouprect             ((unsigned short int)(mk_win_comctl_listview_wm_first +  98ul))
#define mk_win_comctl_listview_wm_getitemtextw             ((unsigned short int)(mk_win_comctl_listview_wm_first + 115ul))
#define mk_win_comctl_listview_wm_setitemtextw             ((unsigned short int)(mk_win_comctl_listview_wm_first + 116ul))
#define mk_win_comctl_listview_wm_getisearchstringw        ((unsigned short int)(mk_win_comctl_listview_wm_first + 117ul))
#define mk_win_comctl_listview_wm_editlabelw               ((unsigned short int)(mk_win_comctl_listview_wm_first + 118ul))
#define mk_win_comctl_listview_wm_setbkimagew              ((unsigned short int)(mk_win_comctl_listview_wm_first + 138ul))
#define mk_win_comctl_listview_wm_getbkimagew              ((unsigned short int)(mk_win_comctl_listview_wm_first + 139ul))
#define mk_win_comctl_listview_wm_setselectedcolumn        ((unsigned short int)(mk_win_comctl_listview_wm_first + 140ul))
#define mk_win_comctl_listview_wm_setview                  ((unsigned short int)(mk_win_comctl_listview_wm_first + 142ul))
#define mk_win_comctl_listview_wm_getview                  ((unsigned short int)(mk_win_comctl_listview_wm_first + 143ul))
#define mk_win_comctl_listview_wm_insertgroup              ((unsigned short int)(mk_win_comctl_listview_wm_first + 145ul))
#define mk_win_comctl_listview_wm_setgroupinfo             ((unsigned short int)(mk_win_comctl_listview_wm_first + 147ul))
#define mk_win_comctl_listview_wm_getgroupinfo             ((unsigned short int)(mk_win_comctl_listview_wm_first + 149ul))
#define mk_win_comctl_listview_wm_removegroup              ((unsigned short int)(mk_win_comctl_listview_wm_first + 150ul))
#define mk_win_comctl_listview_wm_movegroup                ((unsigned short int)(mk_win_comctl_listview_wm_first + 151ul))
#define mk_win_comctl_listview_wm_getgroupcount            ((unsigned short int)(mk_win_comctl_listview_wm_first + 152ul))
#define mk_win_comctl_listview_wm_getgroupinfobyindex      ((unsigned short int)(mk_win_comctl_listview_wm_first + 153ul))
#define mk_win_comctl_listview_wm_moveitemtogroup          ((unsigned short int)(mk_win_comctl_listview_wm_first + 154ul))
#define mk_win_comctl_listview_wm_setgroupmetrics          ((unsigned short int)(mk_win_comctl_listview_wm_first + 155ul))
#define mk_win_comctl_listview_wm_getgroupmetrics          ((unsigned short int)(mk_win_comctl_listview_wm_first + 156ul))
#define mk_win_comctl_listview_wm_enablegroupview          ((unsigned short int)(mk_win_comctl_listview_wm_first + 157ul))
#define mk_win_comctl_listview_wm_sortgroups               ((unsigned short int)(mk_win_comctl_listview_wm_first + 158ul))
#define mk_win_comctl_listview_wm_insertgroupsorted        ((unsigned short int)(mk_win_comctl_listview_wm_first + 159ul))
#define mk_win_comctl_listview_wm_removeallgroups          ((unsigned short int)(mk_win_comctl_listview_wm_first + 160ul))
#define mk_win_comctl_listview_wm_hasgroup                 ((unsigned short int)(mk_win_comctl_listview_wm_first + 161ul))
#define mk_win_comctl_listview_wm_settileviewinfo          ((unsigned short int)(mk_win_comctl_listview_wm_first + 162ul))
#define mk_win_comctl_listview_wm_gettileviewinfo          ((unsigned short int)(mk_win_comctl_listview_wm_first + 163ul))
#define mk_win_comctl_listview_wm_settileinfo              ((unsigned short int)(mk_win_comctl_listview_wm_first + 164ul))
#define mk_win_comctl_listview_wm_gettileinfo              ((unsigned short int)(mk_win_comctl_listview_wm_first + 165ul))
#define mk_win_comctl_listview_wm_setinsertmark            ((unsigned short int)(mk_win_comctl_listview_wm_first + 166ul))
#define mk_win_comctl_listview_wm_getinsertmark            ((unsigned short int)(mk_win_comctl_listview_wm_first + 167ul))
#define mk_win_comctl_listview_wm_insertmarkhittest        ((unsigned short int)(mk_win_comctl_listview_wm_first + 168ul))
#define mk_win_comctl_listview_wm_getinsertmarkrect        ((unsigned short int)(mk_win_comctl_listview_wm_first + 169ul))
#define mk_win_comctl_listview_wm_setinsertmarkcolor       ((unsigned short int)(mk_win_comctl_listview_wm_first + 170ul))
#define mk_win_comctl_listview_wm_getinsertmarkcolor       ((unsigned short int)(mk_win_comctl_listview_wm_first + 171ul))
#define mk_win_comctl_listview_wm_getselectedcolumn        ((unsigned short int)(mk_win_comctl_listview_wm_first + 174ul))
#define mk_win_comctl_listview_wm_isgroupviewenabled       ((unsigned short int)(mk_win_comctl_listview_wm_first + 175ul))
#define mk_win_comctl_listview_wm_getoutlinecolor          ((unsigned short int)(mk_win_comctl_listview_wm_first + 176ul))
#define mk_win_comctl_listview_wm_setoutlinecolor          ((unsigned short int)(mk_win_comctl_listview_wm_first + 177ul))
#define mk_win_comctl_listview_wm_canceleditlabel          ((unsigned short int)(mk_win_comctl_listview_wm_first + 179ul))
#define mk_win_comctl_listview_wm_mapindextoid             ((unsigned short int)(mk_win_comctl_listview_wm_first + 180ul))
#define mk_win_comctl_listview_wm_mapidtoindex             ((unsigned short int)(mk_win_comctl_listview_wm_first + 181ul))
#define mk_win_comctl_listview_wm_isitemvisible            ((unsigned short int)(mk_win_comctl_listview_wm_first + 182ul))
#define mk_win_comctl_listview_wm_getemptytext             ((unsigned short int)(mk_win_comctl_listview_wm_first + 204ul))
#define mk_win_comctl_listview_wm_getfooterrect            ((unsigned short int)(mk_win_comctl_listview_wm_first + 205ul))
#define mk_win_comctl_listview_wm_getfooterinfo            ((unsigned short int)(mk_win_comctl_listview_wm_first + 206ul))
#define mk_win_comctl_listview_wm_getfooteritemrect        ((unsigned short int)(mk_win_comctl_listview_wm_first + 207ul))
#define mk_win_comctl_listview_wm_getfooteritem            ((unsigned short int)(mk_win_comctl_listview_wm_first + 208ul))
#define mk_win_comctl_listview_wm_getitemindexrect         ((unsigned short int)(mk_win_comctl_listview_wm_first + 209ul))
#define mk_win_comctl_listview_wm_setitemindexstate        ((unsigned short int)(mk_win_comctl_listview_wm_first + 210ul))
#define mk_win_comctl_listview_wm_getnextitemindex         ((unsigned short int)(mk_win_comctl_listview_wm_first + 211ul))

#define mk_win_comctl_listview_notify_first               ((unsigned int)(0ul - 100ul))
#define mk_win_comctl_listview_notify_last                ((unsigned int)(0ul - 199ul))
#define mk_win_comctl_listview_notify_itemchanging        ((unsigned int)(mk_win_comctl_listview_notify_first -  0ul))
#define mk_win_comctl_listview_notify_itemchanged         ((unsigned int)(mk_win_comctl_listview_notify_first -  1ul))
#define mk_win_comctl_listview_notify_insertitem          ((unsigned int)(mk_win_comctl_listview_notify_first -  2ul))
#define mk_win_comctl_listview_notify_deleteitem          ((unsigned int)(mk_win_comctl_listview_notify_first -  3ul))
#define mk_win_comctl_listview_notify_deleteallitems      ((unsigned int)(mk_win_comctl_listview_notify_first -  4ul))
#define mk_win_comctl_listview_notify_beginlabeledita     ((unsigned int)(mk_win_comctl_listview_notify_first -  5ul))
#define mk_win_comctl_listview_notify_endlabeledita       ((unsigned int)(mk_win_comctl_listview_notify_first -  6ul))
#define mk_win_comctl_listview_notify_columnclick         ((unsigned int)(mk_win_comctl_listview_notify_first -  8ul))
#define mk_win_comctl_listview_notify_begindrag           ((unsigned int)(mk_win_comctl_listview_notify_first -  9ul))
#define mk_win_comctl_listview_notify_beginrdrag          ((unsigned int)(mk_win_comctl_listview_notify_first - 11ul))
#define mk_win_comctl_listview_notify_odcachehint         ((unsigned int)(mk_win_comctl_listview_notify_first - 13ul))
#define mk_win_comctl_listview_notify_itemactivate        ((unsigned int)(mk_win_comctl_listview_notify_first - 14ul))
#define mk_win_comctl_listview_notify_odstatechanged      ((unsigned int)(mk_win_comctl_listview_notify_first - 15ul))
#define mk_win_comctl_listview_notify_hottrack            ((unsigned int)(mk_win_comctl_listview_notify_first - 21ul))
#define mk_win_comctl_listview_notify_getdispinfoa        ((unsigned int)(mk_win_comctl_listview_notify_first - 50ul))
#define mk_win_comctl_listview_notify_setdispinfoa        ((unsigned int)(mk_win_comctl_listview_notify_first - 51ul))
#define mk_win_comctl_listview_notify_odfinditema         ((unsigned int)(mk_win_comctl_listview_notify_first - 52ul))
#define mk_win_comctl_listview_notify_keydown             ((unsigned int)(mk_win_comctl_listview_notify_first - 55ul))
#define mk_win_comctl_listview_notify_marqueebegin        ((unsigned int)(mk_win_comctl_listview_notify_first - 56ul))
#define mk_win_comctl_listview_notify_getinfotipa         ((unsigned int)(mk_win_comctl_listview_notify_first - 57ul))
#define mk_win_comctl_listview_notify_getinfotipw         ((unsigned int)(mk_win_comctl_listview_notify_first - 58ul))
#define mk_win_comctl_listview_notify_incrementalsearcha  ((unsigned int)(mk_win_comctl_listview_notify_first - 62ul))
#define mk_win_comctl_listview_notify_incrementalsearchw  ((unsigned int)(mk_win_comctl_listview_notify_first - 63ul))
#define mk_win_comctl_listview_notify_columndropdown      ((unsigned int)(mk_win_comctl_listview_notify_first - 64ul))
#define mk_win_comctl_listview_notify_columnoverflowclick ((unsigned int)(mk_win_comctl_listview_notify_first - 66ul))
#define mk_win_comctl_listview_notify_beginlabeleditw     ((unsigned int)(mk_win_comctl_listview_notify_first - 75ul))
#define mk_win_comctl_listview_notify_endlabeleditw       ((unsigned int)(mk_win_comctl_listview_notify_first - 76ul))
#define mk_win_comctl_listview_notify_getdispinfow        ((unsigned int)(mk_win_comctl_listview_notify_first - 77ul))
#define mk_win_comctl_listview_notify_setdispinfow        ((unsigned int)(mk_win_comctl_listview_notify_first - 78ul))
#define mk_win_comctl_listview_notify_odfinditemw         ((unsigned int)(mk_win_comctl_listview_notify_first - 79ul))
#define mk_win_comctl_listview_notify_beginscroll         ((unsigned int)(mk_win_comctl_listview_notify_first - 80ul))
#define mk_win_comctl_listview_notify_endscroll           ((unsigned int)(mk_win_comctl_listview_notify_first - 81ul))
#define mk_win_comctl_listview_notify_linkclick           ((unsigned int)(mk_win_comctl_listview_notify_first - 84ul))
#define mk_win_comctl_listview_notify_getemptymarkup      ((unsigned int)(mk_win_comctl_listview_notify_first - 87ul))

#define mk_win_comctl_listview_ws_report          ((unsigned short int)(0x0001ul))
#define mk_win_comctl_listview_ws_smallicon       ((unsigned short int)(0x0002ul))
#define mk_win_comctl_listview_ws_singlesel       ((unsigned short int)(0x0004ul))
#define mk_win_comctl_listview_ws_showselalways   ((unsigned short int)(0x0008ul))
#define mk_win_comctl_listview_ws_sortascending   ((unsigned short int)(0x0010ul))
#define mk_win_comctl_listview_ws_sortdescending  ((unsigned short int)(0x0020ul))
#define mk_win_comctl_listview_ws_shareimagelists ((unsigned short int)(0x0040ul))
#define mk_win_comctl_listview_ws_nolabelwrap     ((unsigned short int)(0x0080ul))
#define mk_win_comctl_listview_ws_autoarrange     ((unsigned short int)(0x0100ul))
#define mk_win_comctl_listview_ws_editlabels      ((unsigned short int)(0x0200ul))
#define mk_win_comctl_listview_ws_ownerdrawfixed  ((unsigned short int)(0x0400ul))
#define mk_win_comctl_listview_ws_alignleft       ((unsigned short int)(0x0800ul))
#define mk_win_comctl_listview_ws_ownerdata       ((unsigned short int)(0x1000ul))
#define mk_win_comctl_listview_ws_noscroll        ((unsigned short int)(0x2000ul))
#define mk_win_comctl_listview_ws_nocolumnheader  ((unsigned short int)(0x4000ul))
#define mk_win_comctl_listview_ws_nosortheader    ((unsigned short int)(0x8000ul))

#define mk_win_comctl_listview_ws_aligntop      ((unsigned short int)(0x0000ul))
#define mk_win_comctl_listview_ws_icon          ((unsigned short int)(0x0000ul))
#define mk_win_comctl_listview_ws_list          ((unsigned short int)(0x0003ul))
#define mk_win_comctl_listview_ws_typemask      ((unsigned short int)(0x0003ul))
#define mk_win_comctl_listview_ws_alignmask     ((unsigned short int)(0x0c00ul))
#define mk_win_comctl_listview_ws_typestylemask ((unsigned short int)(0xfc00ul))

#define mk_win_comctl_listview_wsex_gridlines             ((unsigned long int)(0x00000001ul))
#define mk_win_comctl_listview_wsex_subitemimages         ((unsigned long int)(0x00000002ul))
#define mk_win_comctl_listview_wsex_checkboxes            ((unsigned long int)(0x00000004ul))
#define mk_win_comctl_listview_wsex_trackselect           ((unsigned long int)(0x00000008ul))
#define mk_win_comctl_listview_wsex_headerdragdrop        ((unsigned long int)(0x00000010ul))
#define mk_win_comctl_listview_wsex_fullrowselect         ((unsigned long int)(0x00000020ul))
#define mk_win_comctl_listview_wsex_oneclickactivate      ((unsigned long int)(0x00000040ul))
#define mk_win_comctl_listview_wsex_twoclickactivate      ((unsigned long int)(0x00000080ul))
#define mk_win_comctl_listview_wsex_flatsb                ((unsigned long int)(0x00000100ul))
#define mk_win_comctl_listview_wsex_regional              ((unsigned long int)(0x00000200ul))
#define mk_win_comctl_listview_wsex_infotip               ((unsigned long int)(0x00000400ul))
#define mk_win_comctl_listview_wsex_underlinehot          ((unsigned long int)(0x00000800ul))
#define mk_win_comctl_listview_wsex_underlinecold         ((unsigned long int)(0x00001000ul))
#define mk_win_comctl_listview_wsex_multiworkareas        ((unsigned long int)(0x00002000ul))
#define mk_win_comctl_listview_wsex_labeltip              ((unsigned long int)(0x00004000ul))
#define mk_win_comctl_listview_wsex_borderselect          ((unsigned long int)(0x00008000ul))
#define mk_win_comctl_listview_wsex_doublebuffer          ((unsigned long int)(0x00010000ul))
#define mk_win_comctl_listview_wsex_hidelabels            ((unsigned long int)(0x00020000ul))
#define mk_win_comctl_listview_wsex_singlerow             ((unsigned long int)(0x00040000ul))
#define mk_win_comctl_listview_wsex_snaptogrid            ((unsigned long int)(0x00080000ul))
#define mk_win_comctl_listview_wsex_simpleselect          ((unsigned long int)(0x00100000ul))
#define mk_win_comctl_listview_wsex_justifycolumns        ((unsigned long int)(0x00200000ul))
#define mk_win_comctl_listview_wsex_transparentbkgnd      ((unsigned long int)(0x00400000ul))
#define mk_win_comctl_listview_wsex_transparentshadowtext ((unsigned long int)(0x00800000ul))
#define mk_win_comctl_listview_wsex_autoautoarrange       ((unsigned long int)(0x01000000ul))
#define mk_win_comctl_listview_wsex_headerinallviews      ((unsigned long int)(0x02000000ul))
#define mk_win_comctl_listview_wsex_unknown_16            ((unsigned long int)(0x04000000ul))
#define mk_win_comctl_listview_wsex_autocheckselect       ((unsigned long int)(0x08000000ul))
#define mk_win_comctl_listview_wsex_autosizecolumns       ((unsigned long int)(0x10000000ul))
#define mk_win_comctl_listview_wsex_unknown_19            ((unsigned long int)(0x20000000ul))
#define mk_win_comctl_listview_wsex_columnsnappoints      ((unsigned long int)(0x40000000ul))
#define mk_win_comctl_listview_wsex_columnoverflow        ((unsigned long int)(0x80000000ul))

#define mk_win_comctl_listview_colflag_fmt          ((unsigned short int)(0x0001ul))
#define mk_win_comctl_listview_colflag_width        ((unsigned short int)(0x0002ul))
#define mk_win_comctl_listview_colflag_text         ((unsigned short int)(0x0004ul))
#define mk_win_comctl_listview_colflag_subitem      ((unsigned short int)(0x0008ul))
#define mk_win_comctl_listview_colflag_image        ((unsigned short int)(0x0010ul))
#define mk_win_comctl_listview_colflag_order        ((unsigned short int)(0x0020ul))
#define mk_win_comctl_listview_colflag_minwidth     ((unsigned short int)(0x0040ul)) /* >= vista */
#define mk_win_comctl_listview_colflag_defaultwidth ((unsigned short int)(0x0080ul)) /* >= vista */
#define mk_win_comctl_listview_colflag_idealwidth   ((unsigned short int)(0x0100ul)) /* >= vista */

#define mk_win_comctl_listview_itmflag_text        ((unsigned long int)(0x00000001ul))
#define mk_win_comctl_listview_itmflag_image       ((unsigned long int)(0x00000002ul))
#define mk_win_comctl_listview_itmflag_param       ((unsigned long int)(0x00000004ul))
#define mk_win_comctl_listview_itmflag_state       ((unsigned long int)(0x00000008ul))
#define mk_win_comctl_listview_itmflag_indent      ((unsigned long int)(0x00000010ul))
#define mk_win_comctl_listview_itmflag_groupid     ((unsigned long int)(0x00000100ul)) /* >= xp */
#define mk_win_comctl_listview_itmflag_columns     ((unsigned long int)(0x00000200ul)) /* >= xp */
#define mk_win_comctl_listview_itmflag_norecompute ((unsigned long int)(0x00000800ul))
#define mk_win_comctl_listview_itmflag_colfmt      ((unsigned long int)(0x00010000ul)) /* >= vista */


struct mk_win_comctl_listview_column_a_s
{
	mk_win_base_types_uint_t m_mask;
	int m_fmt;
	int m_cx;
	mk_win_base_types_char_lpct m_text;
	int m_textmax;
	int m_subitem;
	int m_image;
	int m_order;
	int m_cxmin;
	int m_cxdefault;
	int m_cxideal;
};
mk_win_base_types_make_struct(mk_win_comctl_listview_column_a);

struct mk_win_comctl_listview_column_w_s
{
	mk_win_base_types_uint_t m_mask;
	int m_fmt;
	int m_cx;
	mk_win_base_types_wchar_lpct m_text;
	int m_textmax;
	int m_subitem;
	int m_image;
	int m_order;
	int m_cxmin;
	int m_cxdefault;
	int m_cxideal;
};
mk_win_base_types_make_struct(mk_win_comctl_listview_column_w);

struct mk_win_comctl_listview_column_s
{
	mk_win_base_types_uint_t m_mask;
	int m_fmt;
	int m_cx;
	mk_win_strc_t m_text;
	int m_textmax;
	int m_subitem;
	int m_image;
	int m_order;
	int m_cxmin;
	int m_cxdefault;
	int m_cxideal;
};
mk_win_base_types_make_struct(mk_win_comctl_listview_column);

struct mk_win_comctl_listview_item_s
{
	mk_win_base_types_uint_t m_mask;
	int m_item;
	int m_subitem;
	mk_win_base_types_uint_t m_state;
	mk_win_base_types_uint_t m_statemask;
	mk_win_strc_t m_text;
	int m_textmax;
	int m_image;
	void const* m_param;
	int m_indent;
	int m_groupid;
	mk_win_base_types_uint_t m_ncolumns;
	mk_win_base_types_uint_t* m_columns;
	int* m_colfmt;
	int m_group;
};
mk_win_base_types_make_struct(mk_win_comctl_listview_item);

struct mk_win_comctl_listview_item_a_s
{
	mk_win_base_types_uint_t m_mask;
	int m_item;
	int m_subitem;
	mk_win_base_types_uint_t m_state;
	mk_win_base_types_uint_t m_statemask;
	mk_win_base_types_char_lpct m_text;
	int m_textmax;
	int m_image;
	mk_win_base_user_types_lparam_t m_param;
	int m_indent;
	int m_groupid;
	mk_win_base_types_uint_t m_ncolumns;
	mk_win_base_types_uint_t* m_columns;
	int* m_colfmt;
	int m_group;
};
mk_win_base_types_make_struct(mk_win_comctl_listview_item_a);

struct mk_win_comctl_listview_item_w_s
{
	mk_win_base_types_uint_t m_mask;
	int m_item;
	int m_subitem;
	mk_win_base_types_uint_t m_state;
	mk_win_base_types_uint_t m_statemask;
	mk_win_base_types_wchar_lpct m_text;
	int m_textmax;
	int m_image;
	mk_win_base_user_types_lparam_t m_param;
	int m_indent;
	int m_groupid;
	mk_win_base_types_uint_t m_ncolumns;
	mk_win_base_types_uint_t* m_columns;
	int* m_colfmt;
	int m_group;
};
mk_win_base_types_make_struct(mk_win_comctl_listview_item_w);

struct mk_win_comctl_listview_dispinfo_s
{
	mk_win_base_user_nmhdr_t m_nmhdr;
	union
	{
		mk_win_comctl_listview_item_a_t m_a;
		mk_win_comctl_listview_item_w_t m_w;
	} m_item;
};
mk_win_base_types_make_struct(mk_win_comctl_listview_dispinfo);

struct mk_win_comctl_listview_dispinfo_a_s
{
	mk_win_base_user_nmhdr_t m_nmhdr;
	mk_win_comctl_listview_item_a_t m_item;
};
mk_win_base_types_make_struct(mk_win_comctl_listview_dispinfo_a);

struct mk_win_comctl_listview_dispinfo_w_s
{
	mk_win_base_user_nmhdr_t m_nmhdr;
	mk_win_comctl_listview_item_w_t m_item;
};
mk_win_base_types_make_struct(mk_win_comctl_listview_dispinfo_w);


mk_jumbo int mk_win_comctl_listview_insertcolumn(mk_win_base_user_types_hwnd_t listview, int idx, mk_win_comctl_listview_column_t const* column, mk_win_base_types_intptr_t* ret_idx);


#endif
