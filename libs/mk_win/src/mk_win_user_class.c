#include "mk_win_user_class.h"

#include "mk_win_api.h"
#include "mk_win_str.h"
#include "mk_win_unicode.h"
#include "mk_win_kernel_module.h"

#include "../../mk_win_base/src/mk_win_base_keywords.h"
#include "../../mk_win_base/src/mk_win_base_types.h"
#include "../../mk_win_base/src/mk_win_base_kernel_types.h"
#include "../../mk_win_base/src/mk_win_base_user_functions.h"
#include "../../mk_win_base/src/mk_win_base_user_types.h"

#include "../../mk_utils/src/mk_assert.h"
#include "../../mk_utils/src/mk_try.h"
#include "../../mk_utils/src/mk_jumbo.h"

#include <stddef.h>


#if mk_win_base_platform_osver < mk_win_base_platform_osver_35
#if mk_win_api == mk_win_api_ansi || mk_win_api == mk_win_api_both
static mk_win_base_types_atom_t(mk_win_base_keywords_calling_convention_api*mk_win_user_class_private_register_exa)(mk_win_base_user_types_class_exa_lpt);
#endif
#if mk_win_api == mk_win_api_ansi || mk_win_api == mk_win_api_both
static mk_win_base_types_atom_t(mk_win_base_keywords_calling_convention_api*mk_win_user_class_private_register_exw)(mk_win_base_user_types_class_exw_lpt);
#endif
#endif


mk_jumbo int mk_win_user_class_init(void)
{
	#if mk_win_base_platform_osver < mk_win_base_platform_osver_35
	mk_win_base_kernel_types_hmodule_t user;
	mk_try(mk_win_kernel_module_get_module_handle_user(&user));
	mk_assert(user);
	#if mk_win_api == mk_win_api_ansi || mk_win_api == mk_win_api_both
	mk_try(mk_win_kernel_module_get_proc_address(user, "RegisterClassExA", (mk_win_base_kernel_types_farproc_t*)&mk_win_user_class_private_register_exa));
	#endif
	#if mk_win_api == mk_win_api_ansi || mk_win_api == mk_win_api_both
	mk_try(mk_win_kernel_module_get_proc_address(user, "RegisterClassExW", (mk_win_base_kernel_types_farproc_t*)&mk_win_user_class_private_register_exw));
	#endif
	#endif

	return 0;
}

mk_jumbo int mk_win_user_class_deinit(void)
{
	return 0;
}

mk_jumbo int mk_win_user_class_register(mk_win_user_class_t const* cls_info, mk_win_base_types_atom_t* atom)
{
	#if mk_win_api == mk_win_api_old
	struct mk_win_base_user_types_class_a_s cls;
	mk_win_base_types_atom_t atm;
	mk_assert(cls_info);
	mk_assert(atom);
	cls.m_style = cls_info->m_style;
	cls.m_wndproc = cls_info->m_wndproc;
	cls.m_cls_extra = cls_info->m_cls_extra;
	cls.m_wnd_extra = cls_info->m_wnd_extra;
	cls.m_hinstance = cls_info->m_hinstance;
	cls.m_hicon = cls_info->m_hicon;
	cls.m_hcursor = cls_info->m_hcursor;
	cls.m_background = cls_info->m_background;
	mk_try(mk_win_str_to_narrow_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
	mk_try(mk_win_str_to_narrow_z(cls_info->m_class_name, 1, &cls.m_class_name));
	atm = RegisterClass(&cls);
	*atom = atm;
	return 0;
	#elif mk_win_api == mk_win_api_ansi && mk_win_base_platform_osver < mk_win_base_platform_osver_35
	if(mk_win_user_class_private_register_exa)
	{
		struct mk_win_base_user_types_class_exa_s cls;
		mk_win_base_types_atom_t atm;
		mk_assert(cls_info);
		mk_assert(atom);
		cls.m_size = sizeof(cls);
		cls.m_style = cls_info->m_style;
		cls.m_wndproc = cls_info->m_wndproc;
		cls.m_cls_extra = cls_info->m_cls_extra;
		cls.m_wnd_extra = cls_info->m_wnd_extra;
		cls.m_hinstance = cls_info->m_hinstance;
		cls.m_hicon = cls_info->m_hicon;
		cls.m_hcursor = cls_info->m_hcursor;
		cls.m_background = cls_info->m_background;
		mk_try(mk_win_str_to_narrow_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
		mk_try(mk_win_str_to_narrow_z(cls_info->m_class_name, 1, &cls.m_class_name));
		cls.m_small_icon = cls_info->m_small_icon;
		atm = mk_win_user_class_private_register_exa(&cls);
		*atom = atm;
		return 0;
	}
	else
	{
		struct mk_win_base_user_types_class_a_s cls;
		mk_win_base_types_atom_t atm;
		mk_assert(cls_info);
		mk_assert(atom);
		cls.m_style = cls_info->m_style;
		cls.m_wndproc = cls_info->m_wndproc;
		cls.m_cls_extra = cls_info->m_cls_extra;
		cls.m_wnd_extra = cls_info->m_wnd_extra;
		cls.m_hinstance = cls_info->m_hinstance;
		cls.m_hicon = cls_info->m_hicon;
		cls.m_hcursor = cls_info->m_hcursor;
		cls.m_background = cls_info->m_background;
		mk_try(mk_win_str_to_narrow_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
		mk_try(mk_win_str_to_narrow_z(cls_info->m_class_name, 1, &cls.m_class_name));
		atm = RegisterClassA(&cls);
		*atom = atm;
		return 0;
	}
	#elif mk_win_api == mk_win_api_ansi && mk_win_base_platform_osver >= mk_win_base_platform_osver_35
	struct mk_win_base_user_types_class_exa_s cls;
	mk_win_base_types_atom_t atm;
	mk_assert(cls_info);
	mk_assert(atom);
	cls.m_size = sizeof(cls);
	cls.m_style = cls_info->m_style;
	cls.m_wndproc = cls_info->m_wndproc;
	cls.m_cls_extra = cls_info->m_cls_extra;
	cls.m_wnd_extra = cls_info->m_wnd_extra;
	cls.m_hinstance = cls_info->m_hinstance;
	cls.m_hicon = cls_info->m_hicon;
	cls.m_hcursor = cls_info->m_hcursor;
	cls.m_background = cls_info->m_background;
	mk_try(mk_win_str_to_narrow_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
	mk_try(mk_win_str_to_narrow_z(cls_info->m_class_name, 1, &cls.m_class_name));
	cls.m_small_icon = cls_info->m_small_icon;
	atm = RegisterClassExA(&cls);
	*atom = atm;
	return 0;
	#elif mk_win_api == mk_win_api_wide && mk_win_base_platform_osver < mk_win_base_platform_osver_35
	if(mk_win_user_class_private_register_exw)
	{
		struct mk_win_base_user_types_class_exw_s cls;
		mk_win_base_types_atom_t atm;
		mk_assert(cls_info);
		mk_assert(atom);
		cls.m_size = sizeof(cls);
		cls.m_style = cls_info->m_style;
		cls.m_wndproc = cls_info->m_wndproc;
		cls.m_cls_extra = cls_info->m_cls_extra;
		cls.m_wnd_extra = cls_info->m_wnd_extra;
		cls.m_hinstance = cls_info->m_hinstance;
		cls.m_hicon = cls_info->m_hicon;
		cls.m_hcursor = cls_info->m_hcursor;
		cls.m_background = cls_info->m_background;
		mk_try(mk_win_str_to_wide_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
		mk_try(mk_win_str_to_wide_z(cls_info->m_class_name, 1, &cls.m_class_name));
		cls.m_small_icon = cls_info->m_small_icon;
		atm = mk_win_user_class_private_register_exw(&cls);
		*atom = atm;
		return 0;
	}
	else
	{
		struct mk_win_base_user_types_class_w_s cls;
		mk_win_base_types_atom_t atm;
		mk_assert(cls_info);
		mk_assert(atom);
		cls.m_style = cls_info->m_style;
		cls.m_wndproc = cls_info->m_wndproc;
		cls.m_cls_extra = cls_info->m_cls_extra;
		cls.m_wnd_extra = cls_info->m_wnd_extra;
		cls.m_hinstance = cls_info->m_hinstance;
		cls.m_hicon = cls_info->m_hicon;
		cls.m_hcursor = cls_info->m_hcursor;
		cls.m_background = cls_info->m_background;
		mk_try(mk_win_str_to_wide_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
		mk_try(mk_win_str_to_wide_z(cls_info->m_class_name, 1, &cls.m_class_name));
		atm = RegisterClassW(&cls);
		*atom = atm;
		return 0;
	}
	#elif mk_win_api == mk_win_api_wide && mk_win_base_platform_osver >= mk_win_base_platform_osver_35
	struct mk_win_base_user_types_class_exw_s cls;
	mk_win_base_types_atom_t atm;
	mk_assert(cls_info);
	mk_assert(atom);
	cls.m_size = sizeof(cls);
	cls.m_style = cls_info->m_style;
	cls.m_wndproc = cls_info->m_wndproc;
	cls.m_cls_extra = cls_info->m_cls_extra;
	cls.m_wnd_extra = cls_info->m_wnd_extra;
	cls.m_hinstance = cls_info->m_hinstance;
	cls.m_hicon = cls_info->m_hicon;
	cls.m_hcursor = cls_info->m_hcursor;
	cls.m_background = cls_info->m_background;
	mk_try(mk_win_str_to_wide_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
	mk_try(mk_win_str_to_wide_z(cls_info->m_class_name, 1, &cls.m_class_name));
	cls.m_small_icon = cls_info->m_small_icon;
	atm = RegisterClassExW(&cls);
	*atom = atm;
	return 0;
	#elif mk_win_api == mk_win_api_both && mk_win_base_platform_osver < mk_win_base_platform_osver_35
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		if(mk_win_user_class_private_register_exa)
		{
			struct mk_win_base_user_types_class_exa_s cls;
			mk_win_base_types_atom_t atm;
			mk_assert(cls_info);
			mk_assert(atom);
			cls.m_size = sizeof(cls);
			cls.m_style = cls_info->m_style;
			cls.m_wndproc = cls_info->m_wndproc;
			cls.m_cls_extra = cls_info->m_cls_extra;
			cls.m_wnd_extra = cls_info->m_wnd_extra;
			cls.m_hinstance = cls_info->m_hinstance;
			cls.m_hicon = cls_info->m_hicon;
			cls.m_hcursor = cls_info->m_hcursor;
			cls.m_background = cls_info->m_background;
			mk_try(mk_win_str_to_narrow_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
			mk_try(mk_win_str_to_narrow_z(cls_info->m_class_name, 1, &cls.m_class_name));
			cls.m_small_icon = cls_info->m_small_icon;
			atm = mk_win_user_class_private_register_exa(&cls);
			*atom = atm;
			return 0;
		}
		else
		{
			struct mk_win_base_user_types_class_a_s cls;
			mk_win_base_types_atom_t atm;
			mk_assert(cls_info);
			mk_assert(atom);
			cls.m_style = cls_info->m_style;
			cls.m_wndproc = cls_info->m_wndproc;
			cls.m_cls_extra = cls_info->m_cls_extra;
			cls.m_wnd_extra = cls_info->m_wnd_extra;
			cls.m_hinstance = cls_info->m_hinstance;
			cls.m_hicon = cls_info->m_hicon;
			cls.m_hcursor = cls_info->m_hcursor;
			cls.m_background = cls_info->m_background;
			mk_try(mk_win_str_to_narrow_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
			mk_try(mk_win_str_to_narrow_z(cls_info->m_class_name, 1, &cls.m_class_name));
			atm = RegisterClassA(&cls);
			*atom = atm;
			return 0;
		}
	}
	else
	{
		if(mk_win_user_class_private_register_exw)
		{
			struct mk_win_base_user_types_class_exw_s cls;
			mk_win_base_types_atom_t atm;
			mk_assert(cls_info);
			mk_assert(atom);
			cls.m_size = sizeof(cls);
			cls.m_style = cls_info->m_style;
			cls.m_wndproc = cls_info->m_wndproc;
			cls.m_cls_extra = cls_info->m_cls_extra;
			cls.m_wnd_extra = cls_info->m_wnd_extra;
			cls.m_hinstance = cls_info->m_hinstance;
			cls.m_hicon = cls_info->m_hicon;
			cls.m_hcursor = cls_info->m_hcursor;
			cls.m_background = cls_info->m_background;
			mk_try(mk_win_str_to_wide_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
			mk_try(mk_win_str_to_wide_z(cls_info->m_class_name, 1, &cls.m_class_name));
			cls.m_small_icon = cls_info->m_small_icon;
			atm = mk_win_user_class_private_register_exw(&cls);
			*atom = atm;
			return 0;
		}
		else
		{
			struct mk_win_base_user_types_class_w_s cls;
			mk_win_base_types_atom_t atm;
			mk_assert(cls_info);
			mk_assert(atom);
			cls.m_style = cls_info->m_style;
			cls.m_wndproc = cls_info->m_wndproc;
			cls.m_cls_extra = cls_info->m_cls_extra;
			cls.m_wnd_extra = cls_info->m_wnd_extra;
			cls.m_hinstance = cls_info->m_hinstance;
			cls.m_hicon = cls_info->m_hicon;
			cls.m_hcursor = cls_info->m_hcursor;
			cls.m_background = cls_info->m_background;
			mk_try(mk_win_str_to_wide_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
			mk_try(mk_win_str_to_wide_z(cls_info->m_class_name, 1, &cls.m_class_name));
			atm = RegisterClassW(&cls);
			*atom = atm;
			return 0;
		}
	}
	#elif mk_win_api == mk_win_api_both && mk_win_base_platform_osver >= mk_win_base_platform_osver_35
	int unicode_enabled;
	mk_try(mk_win_unicode_enabled(&unicode_enabled));
	if(!unicode_enabled)
	{
		struct mk_win_base_user_types_class_exa_s cls;
		mk_win_base_types_atom_t atm;
		mk_assert(cls_info);
		mk_assert(atom);
		cls.m_size = sizeof(cls);
		cls.m_style = cls_info->m_style;
		cls.m_wndproc = cls_info->m_wndproc;
		cls.m_cls_extra = cls_info->m_cls_extra;
		cls.m_wnd_extra = cls_info->m_wnd_extra;
		cls.m_hinstance = cls_info->m_hinstance;
		cls.m_hicon = cls_info->m_hicon;
		cls.m_hcursor = cls_info->m_hcursor;
		cls.m_background = cls_info->m_background;
		mk_try(mk_win_str_to_narrow_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
		mk_try(mk_win_str_to_narrow_z(cls_info->m_class_name, 1, &cls.m_class_name));
		cls.m_small_icon = cls_info->m_small_icon;
		atm = RegisterClassExA(&cls);
		*atom = atm;
		return 0;
	}
	else
	{
		struct mk_win_base_user_types_class_exw_s cls;
		mk_win_base_types_atom_t atm;
		mk_assert(cls_info);
		mk_assert(atom);
		cls.m_size = sizeof(cls);
		cls.m_style = cls_info->m_style;
		cls.m_wndproc = cls_info->m_wndproc;
		cls.m_cls_extra = cls_info->m_cls_extra;
		cls.m_wnd_extra = cls_info->m_wnd_extra;
		cls.m_hinstance = cls_info->m_hinstance;
		cls.m_hicon = cls_info->m_hicon;
		cls.m_hcursor = cls_info->m_hcursor;
		cls.m_background = cls_info->m_background;
		mk_try(mk_win_str_to_wide_z(cls_info->m_menu_name, 0, &cls.m_menu_name));
		mk_try(mk_win_str_to_wide_z(cls_info->m_class_name, 1, &cls.m_class_name));
		cls.m_small_icon = cls_info->m_small_icon;
		atm = RegisterClassExW(&cls);
		*atom = atm;
		return 0;
	}
	#endif
}
