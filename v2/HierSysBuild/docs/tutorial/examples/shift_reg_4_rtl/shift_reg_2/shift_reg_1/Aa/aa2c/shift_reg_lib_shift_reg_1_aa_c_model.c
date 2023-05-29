#include <pthread.h>
#include <pthreadUtils.h>
#include <Pipes.h>
#include <shift_reg_lib_shift_reg_1_aa_c_model_internal.h>
#include <shift_reg_lib_shift_reg_1_aa_c_model.h>
FILE* shift_reg_lib_shift_reg_1___report_log_file__ = NULL;
int shift_reg_lib_shift_reg_1___trace_on__ = 0;
void shift_reg_lib_shift_reg_1__set_trace_file(FILE* fp) {
shift_reg_lib_shift_reg_1___report_log_file__ = fp;
}
void shift_reg_lib_shift_reg_1___init_aa_globals__() 
{
register_pipe("in_data", 2, 32, 0);\
register_pipe("out_data", 2, 32, 0);\
}
void _shift_reg_lib_shift_reg_1_global_storage_initializer__()
{
MUTEX_DECL(shift_reg_lib_shift_reg_1__global_storage_initializer__series_block_stmt_3_c_mutex_);
MUTEX_LOCK(shift_reg_lib_shift_reg_1__global_storage_initializer__series_block_stmt_3_c_mutex_);
shift_reg_lib_shift_reg_1__global_storage_initializer__inner_inarg_prep_macro__; 
/* null */ ;
shift_reg_lib_shift_reg_1__global_storage_initializer__inner_outarg_prep_macro__; 
MUTEX_UNLOCK(shift_reg_lib_shift_reg_1__global_storage_initializer__series_block_stmt_3_c_mutex_);
}
void shift_reg_lib_shift_reg_1_global_storage_initializer_()
{
shift_reg_lib_shift_reg_1__global_storage_initializer__outer_arg_decl_macro__;
_shift_reg_lib_shift_reg_1_global_storage_initializer__();
shift_reg_lib_shift_reg_1__global_storage_initializer__outer_op_xfer_macro__;
}


void _shift_reg_lib_shift_reg_1_shift_reg_1_daemon_()
{
MUTEX_DECL(shift_reg_lib_shift_reg_1__shift_reg_1_daemon_series_block_stmt_6_c_mutex_);
MUTEX_LOCK(shift_reg_lib_shift_reg_1__shift_reg_1_daemon_series_block_stmt_6_c_mutex_);
shift_reg_lib_shift_reg_1__shift_reg_1_daemon_inner_inarg_prep_macro__; 
shift_reg_lib_shift_reg_1__shift_reg_1_daemon_branch_block_stmt_7_c_export_decl_macro_; 
{
// merge  file .Aa/prog.linked.opt.aa, line 19
shift_reg_lib_shift_reg_1__shift_reg_1_daemon_merge_stmt_8_c_preamble_macro_; 
shift_reg_lib_shift_reg_1__shift_reg_1_daemon_merge_stmt_8_c_postamble_macro_; 
// 		X := in_data $buffering 1// bits of buffering = 32. 
shift_reg_lib_shift_reg_1__shift_reg_1_daemon_assign_stmt_11_c_macro_; 
// 		out_data := X $buffering 1// bits of buffering = 32. 
shift_reg_lib_shift_reg_1__shift_reg_1_daemon_assign_stmt_14_c_macro_; 
/* 		$place[loopback]
*/  goto loopback_7;
shift_reg_lib_shift_reg_1__shift_reg_1_daemon_branch_block_stmt_7_c_export_apply_macro_;
}
shift_reg_lib_shift_reg_1__shift_reg_1_daemon_inner_outarg_prep_macro__; 
MUTEX_UNLOCK(shift_reg_lib_shift_reg_1__shift_reg_1_daemon_series_block_stmt_6_c_mutex_);
}
void shift_reg_lib_shift_reg_1_shift_reg_1_daemon()
{
shift_reg_lib_shift_reg_1__shift_reg_1_daemon_outer_arg_decl_macro__;
_shift_reg_lib_shift_reg_1_shift_reg_1_daemon_();
shift_reg_lib_shift_reg_1__shift_reg_1_daemon_outer_op_xfer_macro__;
}


DEFINE_THREAD(shift_reg_lib_shift_reg_1_shift_reg_1_daemon);
PTHREAD_DECL(shift_reg_lib_shift_reg_1_shift_reg_1_daemon);
void shift_reg_lib_shift_reg_1_start_daemons(FILE* fp, int trace_on) {
shift_reg_lib_shift_reg_1___report_log_file__ = fp;
shift_reg_lib_shift_reg_1___trace_on__ = trace_on;
shift_reg_lib_shift_reg_1___init_aa_globals__(); 
PTHREAD_CREATE(shift_reg_lib_shift_reg_1_shift_reg_1_daemon);
}
void shift_reg_lib_shift_reg_1_stop_daemons() {
PTHREAD_CANCEL(shift_reg_lib_shift_reg_1_shift_reg_1_daemon);
}
