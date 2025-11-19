.section .init

.option norvc

.type start, @function
.global start
start:
	.cfi_startproc
	
.option push
.option norelax
	la gp, global_pointer
.option pop
	
	
	csrw satp, zero
	
	
	la sp, stack_top
	
	
	la t5, bss_start
	la t6, bss_end

	call _starts
	
	.cfi_endproc

.end
