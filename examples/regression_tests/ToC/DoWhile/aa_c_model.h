#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <BitVectors.h>
#include <pipeHandler.h>
void _set_trace_file (FILE * fp);
// object initialization 
void __init_aa_globals__ ();
void Daemon ();
void _Daemon_ ();

#define _Daemon_inner_inarg_prep_macro__
#define _Daemon_branch_block_stmt_6_c_export_decl_macro_ __declare_static_bit_vector(I,8);\
__declare_static_bit_vector(gflag,1);\
__declare_static_bit_vector(NI,8);\


#define _Daemon_merge_stmt_8_c_preamble_macro_ uint8_t merge_stmt_8_entry_flag;\
merge_stmt_8_entry_flag = do_while_entry_flag;\
goto merge_stmt_8_run;\
merge_stmt_8_run: ;\

#define _Daemon_phi_stmt_9_c_macro_ __declare_static_bit_vector(konst_12,8);\
bit_vector_clear(&konst_12);\
__declare_static_bit_vector(type_cast_13,8);\
bit_vector_clear(&type_cast_13);\
if(do_while_loopback_flag) {\
bit_vector_cast_to_bit_vector(0, &(I), &(NI));\
}\
else {\
__declare_static_bit_vector(konst_12,8);\
bit_vector_clear(&konst_12);\
__declare_static_bit_vector(type_cast_13,8);\
bit_vector_clear(&type_cast_13);\
bit_vector_clear(&konst_12);\
bit_vector_bitcast_to_bit_vector( &(type_cast_13), &(konst_12));\
bit_vector_cast_to_bit_vector(0, &(I), &(type_cast_13));\
}\
;
;

#define _Daemon_merge_stmt_8_c_postamble_macro_ merge_stmt_8_entry_flag = 0;

#define _Daemon_assign_stmt_20_c_macro_ __declare_static_bit_vector(RPIPE_in_data_19,32);\
read_bit_vector_from_pipe("in_data",&(RPIPE_in_data_19));\
bit_vector_cast_to_bit_vector(0, &((T[bit_vector_to_uint64(0, &I)][bit_vector_to_uint64(0, &I)])), &(RPIPE_in_data_19));\
;

#define _Daemon_assign_stmt_26_c_macro_ __declare_static_bit_vector(konst_23,8);\
bit_vector_clear(&konst_23);\
__declare_static_bit_vector(UGE_u8_u1_24,1);\
bit_vector_clear(&konst_23);\
bit_vector_greater_equal(0, &(I), &(konst_23), &(UGE_u8_u1_24));\
bit_vector_cast_to_bit_vector(0, &(gflag), &(UGE_u8_u1_24));\
;

#define _Daemon_assign_stmt_36_c_macro_ if (has_undefined_bit(&gflag)) {fprintf(stderr, "Error: variable gflag has undefined value (%s) at test point.\n", to_string(&gflag));assert(0);} \
__declare_static_bit_vector(MUL_u32_u32_35,32);\
if (bit_vector_to_uint64(0, &gflag)) {\
bit_vector_mul( &((T[bit_vector_to_uint64(0, &I)][bit_vector_to_uint64(0, &I)])), &((T[bit_vector_to_uint64(0, &I)][bit_vector_to_uint64(0, &I)])), &(MUL_u32_u32_35));\
write_bit_vector_to_pipe("out_data",&(MUL_u32_u32_35));\
}
;

#define _Daemon_stmt_38_c_macro_ if (bit_vector_to_uint64(0, &gflag)) {\
if (__trace_on__) {\
__trace("TTTT",1);\
}\
}\

#define _Daemon_assign_stmt_43_c_macro_ __declare_static_bit_vector(konst_41,8);\
bit_vector_clear(&konst_41);\
konst_41.val.byte_array[0] = 1;\
__declare_static_bit_vector(ADD_u8_u8_42,8);\
bit_vector_clear(&konst_41);\
konst_41.val.byte_array[0] = 1;\
bit_vector_plus( &(I), &(konst_41), &(ADD_u8_u8_42));\
bit_vector_cast_to_bit_vector(0, &(NI), &(ADD_u8_u8_42));\
;
;

#define _Daemon_branch_block_stmt_6_c_export_apply_macro_ ;

#define _Daemon_inner_outarg_prep_macro__ ;

#define _Daemon_outer_arg_decl_macro__ ;

#define _Daemon_outer_op_xfer_macro__ ;
void start_daemons (FILE * fp, int trace_on);
void stop_daemons ();
