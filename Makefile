include ${PETSC_DIR}/lib/petsc/conf/variables
include ${PETSC_DIR}/lib/petsc/conf/rules
include ${SLEPC_DIR}/lib/slepc/conf/slepc_common


petsc_vec_mat_example: petsc_vec_mat_example.o chkopts
	-${CLINKER} -o petsc_vec_mat_example petsc_vec_mat_example.o ${PETSC_LIB}
	${RM} petsc_vec_mat_example.o

