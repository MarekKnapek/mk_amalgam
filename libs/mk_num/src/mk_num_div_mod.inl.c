#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_minmax.h"


#if(mk_num_div_mod_use_r1d2 == 0)
#define mk_num_div_mod_prefix r3d2
#elif(mk_num_div_mod_use_r1d2 == 1)
#define mk_num_div_mod_prefix r2d1
#define mk_num_div_mod_big_type mk_num_div_mod_mid_type
#endif

#define mk_num_div_mod mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_num_div_mod_, mk_num_div_mod_small_name), _), mk_num_div_mod_len_x), _), mk_num_div_mod_len_y), _), mk_num_div_mod_prefix)


mk_lang_jumbo void mk_num_div_mod(mk_num_div_mod_small_type const* x, mk_num_div_mod_small_type const* y, mk_num_div_mod_small_type* res_div, mk_num_div_mod_small_type* res_mod)
{
	#define lend mk_num_div_mod_len_x
	#define lenm mk_num_div_mod_len_y

	int lenx;
	int i;
	int leny;
	mk_num_div_mod_small_type mx;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(res_div);
	mk_lang_assert(res_mod);

	lenx = 0;
	for(i = 0; i != mk_num_div_mod_len_x; ++i)
	{
		if(x[mk_num_div_mod_len_x - 1 - i] != 0)
		{
			lenx = mk_num_div_mod_len_x - i;
			break;
		}
	}
	leny = 0;
	for(i = 0; i != mk_num_div_mod_len_y; ++i)
	{
		if(y[mk_num_div_mod_len_y - 1 - i] != 0)
		{
			leny = mk_num_div_mod_len_y - i;
			break;
		}
	}
	if(leny == 0)
	{
		mx = 0;
		--mx;
		for(i = 0; i != lend; ++i)
		{
			res_div[i] = mx;
		}
		for(i = 0; i != lenm; ++i)
		{
			res_mod[i] = mx;
		}
		return;
	}
	if(lenx == 0)
	{
		for(i = 0; i != lend; ++i)
		{
			res_div[i] = 0;
		}
		for(i = 0; i != lenm; ++i)
		{
			res_mod[i] = 0;
		}
		return;
	}
	if(lenx < leny)
	{
		for(i = 0; i != lend; ++i)
		{
			res_div[i] = 0;
		}
		for(i = 0; i != lenx; ++i)
		{
			res_mod[i] = x[i];
		}
		for(i = lenx; i != lenm; ++i)
		{
			res_mod[i] = 0;
		}
		return;
	}
	if(lenx == leny)
	{
		for(i = 0; i != lenx; ++i)
		{
			if(x[lenx - 1 - i] < y[lenx - 1 - i])
			{
				for(i = 0; i != lend; ++i)
				{
					res_div[i] = 0;
				}
				for(i = 0; i != lenx; ++i)
				{
					res_mod[i] = x[i];
				}
				for(i = lenx; i != lenm; ++i)
				{
					res_mod[i] = 0;
				}
				return;
			}
			else if(y[lenx - 1 - i] < x[lenx - 1 - i])
			{
				break;
			}
		}
		if(i == lenx)
		{
			res_div[0] = 1;
			for(i = 1; i != lend; ++i)
			{
				res_div[i] = 0;
			}
			for(i = 0; i != lenm; ++i)
			{
				res_mod[i] = 0;
			}
			return;
		}
	}
	if(leny == 1)
	{
		mk_num_div_mod_small_type yy;
		mk_num_div_mod_small_type d;
		mk_num_div_mod_small_type m;
		mk_num_div_mod_mid_type tmp;

		yy = y[0];
		for(i = 0; i != lend - lenx; ++i)
		{
			res_div[lend - 1 - i] = 0;
		}
		for(i = 0; i != lenm - 1; ++i)
		{
			res_mod[lenm - 1 - i] = 0;
		}
		d = ((mk_num_div_mod_small_type)(x[lenx - 1] / yy));
		m = ((mk_num_div_mod_small_type)(x[lenx - 1] % yy));
		res_div[lenx - 1] = d;
		for(i = 1; i != lenx; ++i)
		{
			tmp = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(m)) << (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit))) | ((mk_num_div_mod_mid_type)(x[lenx - 1 - i]))));
			d = ((mk_num_div_mod_small_type)(tmp / yy));
			m = ((mk_num_div_mod_small_type)(tmp % yy));
			res_div[lenx - 1 - i] = d;
		}
		res_mod[0] = m;
		return;
	}
	{
		mk_num_div_mod_small_type f;
		mk_num_div_mod_mid_type tmp;
		mk_num_div_mod_small_type carry;
		mk_num_div_mod_small_type xx[mk_num_div_mod_len_x + 1];
		mk_num_div_mod_small_type yy[mk_num_div_mod_len_y];
		int id;

		for(i = 0; i != lend - (lenx - leny + 1); ++i)
		{
			res_div[lend - 1 - i] = 0;
		}
		for(i = 0; i != lenm - leny; ++i)
		{
			res_mod[lenm - 1 - i] = 0;
		}
		f =
			((mk_num_div_mod_small_type)(
				((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(1)) << (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit))) /
				((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(y[leny - 1])) + ((mk_num_div_mod_mid_type)(1))))
			));
		tmp = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(x[0])) * ((mk_num_div_mod_mid_type)(f))));
		xx[0] = ((mk_num_div_mod_small_type)(tmp));
		carry = ((mk_num_div_mod_small_type)(tmp >> (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit)));
		for(i = 1; i != lenx; ++i)
		{
			tmp = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(x[i])) * ((mk_num_div_mod_mid_type)(f)))) + ((mk_num_div_mod_mid_type)(carry))));
			xx[i] = ((mk_num_div_mod_small_type)(tmp));
			carry = ((mk_num_div_mod_small_type)(tmp >> (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit)));
		}
		xx[lenx] = carry;
		tmp = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(y[0])) * ((mk_num_div_mod_mid_type)(f))));
		yy[0] = ((mk_num_div_mod_small_type)(tmp));
		carry = ((mk_num_div_mod_small_type)(tmp >> (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit)));
		for(i = 1; i != leny - 1; ++i)
		{
			tmp = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(y[i])) * ((mk_num_div_mod_mid_type)(f)))) + ((mk_num_div_mod_mid_type)(carry))));
			yy[i] = ((mk_num_div_mod_small_type)(tmp));
			carry = ((mk_num_div_mod_small_type)(tmp >> (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit)));
		}
		tmp = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(y[i])) * ((mk_num_div_mod_mid_type)(f)))) + ((mk_num_div_mod_mid_type)(carry))));
		yy[i] = ((mk_num_div_mod_small_type)(tmp));
		mk_lang_assert(((mk_num_div_mod_small_type)(tmp >> (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit))) == 0);
		for(id = 0; id != lenx - leny + 1; ++id)
		{
			mk_num_div_mod_big_type rn;
			mk_num_div_mod_mid_type dn;
			mk_num_div_mod_mid_type qtmid;
			mk_num_div_mod_small_type qt;
			mk_num_div_mod_small_type dq[mk_num_div_mod_len_y + 1];
			mk_lang_bool_t overshoot;
			mk_lang_bool_t borrow2;
			mk_lang_bool_t borrow1;

			#if(mk_num_div_mod_use_r1d2 == 0)
			rn =
				((mk_num_div_mod_big_type)(
					((mk_num_div_mod_big_type)(
						((mk_num_div_mod_big_type)(((mk_num_div_mod_big_type)(xx[lenx - id])) << (2 * sizeof(mk_num_div_mod_small_type) * mk_lang_charbit))) |
						((mk_num_div_mod_big_type)(((mk_num_div_mod_big_type)(xx[lenx - id - 1])) << (sizeof(mk_num_div_mod_small_type ) * mk_lang_charbit)))
					)) |
					((mk_num_div_mod_big_type)(xx[lenx - id - 2]))
				));
			dn =
				((mk_num_div_mod_mid_type)(
					((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(yy[leny - 1])) << (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit))) |
					((mk_num_div_mod_mid_type)(yy[leny - 2]))
				));
			#elif(mk_num_div_mod_use_r1d2 == 1)
			rn =
				((mk_num_div_mod_mid_type)(
						((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(xx[lenx - id])) << (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit))) |
						((mk_num_div_mod_mid_type)(xx[lenx - id - 1]))
				));
			dn = ((mk_num_div_mod_mid_type)(yy[leny - 1]));
			#endif
			qtmid = ((mk_num_div_mod_mid_type)(rn / dn));
			qt = ((mk_num_div_mod_small_type)(mk_lang_min(qtmid, ((mk_num_div_mod_small_type)(((mk_num_div_mod_small_type)(0)) - ((mk_num_div_mod_small_type)(1)))))));
			tmp = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(yy[0])) * ((mk_num_div_mod_mid_type)(qt))));
			dq[0] = ((mk_num_div_mod_small_type)(tmp));
			carry = ((mk_num_div_mod_small_type)(tmp >> (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit)));
			for(i = 1; i != leny; ++i)
			{
				tmp = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(yy[i])) * ((mk_num_div_mod_mid_type)(qt)))) + ((mk_num_div_mod_mid_type)(carry))));
				dq[i] = ((mk_num_div_mod_small_type)(tmp));
				carry = ((mk_num_div_mod_small_type)(tmp >> (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit)));
			}
			dq[leny] = carry;
			overshoot = mk_lang_false;
			for(i = 0; i != leny + 1; ++i)
			{
				if(dq[leny - i] > xx[lenx - id - i]) { overshoot = mk_lang_true; break; }
				if(dq[leny - i] < xx[lenx - id - i]) { overshoot = mk_lang_false; break; }
			}
			if(overshoot)
			{
				--qt;
				tmp = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(yy[0])) * ((mk_num_div_mod_mid_type)(qt))));
				dq[0] = ((mk_num_div_mod_small_type)(tmp));
				carry = ((mk_num_div_mod_small_type)(tmp >> (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit)));
				for(i = 1; i != leny; ++i)
				{
					tmp = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(yy[i])) * ((mk_num_div_mod_mid_type)(qt)))) + ((mk_num_div_mod_mid_type)(carry))));
					dq[i] = ((mk_num_div_mod_small_type)(tmp));
					carry = ((mk_num_div_mod_small_type)(tmp >> (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit)));
				}
				dq[leny] = carry;
				#if(mk_num_div_mod_use_r1d2 == 0)
				#elif(mk_num_div_mod_use_r1d2 == 1)
				overshoot = mk_lang_false;
				for(i = 0; i != leny + 1; ++i)
				{
					if(dq[leny - i] > xx[lenx - id - i]) { overshoot = mk_lang_true; break; }
					if(dq[leny - i] < xx[lenx - id - i]) { overshoot = mk_lang_false; break; }
				}
				if(overshoot)
				{
					--qt;
					tmp = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(yy[0])) * ((mk_num_div_mod_mid_type)(qt))));
					dq[0] = ((mk_num_div_mod_small_type)(tmp));
					carry = ((mk_num_div_mod_small_type)(tmp >> (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit)));
					for(i = 1; i != leny; ++i)
					{
						tmp = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(yy[i])) * ((mk_num_div_mod_mid_type)(qt)))) + ((mk_num_div_mod_mid_type)(carry))));
						dq[i] = ((mk_num_div_mod_small_type)(tmp));
						carry = ((mk_num_div_mod_small_type)(tmp >> (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit)));
					}
					dq[leny] = carry;
				}
				#endif
			}
			res_div[lenx - leny - id] = qt;
			borrow2 = (xx[lenx - leny - id] < dq[0]);
			xx[lenx - leny - id] = ((mk_num_div_mod_small_type)(xx[lenx - leny - id] - dq[0]));
			borrow1 = borrow2;
			for(i = 1; i != leny; ++i)
			{
				borrow2 = borrow1 ? (xx[lenx - leny - id + i] <= dq[i]) : (xx[lenx - leny - id + i] < dq[i]);
				xx[lenx - leny - id + i] = ((mk_num_div_mod_small_type)(((mk_num_div_mod_small_type)(xx[lenx - leny - id + i] - dq[i])) - borrow1));
				borrow1 = borrow2;
			}
			xx[lenx - leny - id + i] = ((mk_num_div_mod_small_type)(((mk_num_div_mod_small_type)(xx[lenx - leny - id + i] - dq[i])) - borrow1));
			mk_lang_assert(xx[lenx - leny - id + i] == 0);
		}
		if(f == 1)
		{
			for(i = 0; i != leny; ++i)
			{
				res_mod[(lenm - 1) - (lenm - leny) - i] = xx[leny - 1 - i];
			}
		}
		else
		{
			mk_num_div_mod_small_type m;
			mk_num_div_mod_small_type o;
			mk_num_div_mod_mid_type t;

			m = ((mk_num_div_mod_small_type)(xx[leny - 1] / f));
			o = ((mk_num_div_mod_small_type)(xx[leny - 1] - ((mk_num_div_mod_small_type)(m * f))));
			res_mod[(lenm - 1) - (lenm - leny)] = m;
			for(i = 1; i != leny - 1; ++i)
			{
				t = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(o)) << (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit))) | ((mk_num_div_mod_mid_type)(xx[leny - 1 - i]))));
				m = ((mk_num_div_mod_small_type)(t / f));
				o = ((mk_num_div_mod_small_type)(xx[leny - 1 - i] - ((mk_num_div_mod_small_type)(m * f))));
				res_mod[(lenm - 1) - (lenm - leny) - i] = m;
			}
			t = ((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(((mk_num_div_mod_mid_type)(o)) << (sizeof(mk_num_div_mod_small_type) * mk_lang_charbit))) | ((mk_num_div_mod_mid_type)(xx[leny - 1 - i]))));
			m = ((mk_num_div_mod_small_type)(t / f));
			mk_lang_assert(((mk_num_div_mod_small_type)(xx[leny - 1 - i] - ((mk_num_div_mod_small_type)(m * f)))) == 0);
			res_mod[(lenm - 1) - (lenm - leny) - i] = m;
		}
	}

	#undef lend
	#undef lenm
}


#undef mk_num_div_mod_prefix
#undef mk_num_div_mod


#undef mk_num_div_mod_len_x
#undef mk_num_div_mod_len_y
#undef mk_num_div_mod_use_r1d2
#undef mk_num_div_mod_small_name
#undef mk_num_div_mod_small_type
#undef mk_num_div_mod_mid_type
#undef mk_num_div_mod_big_type
