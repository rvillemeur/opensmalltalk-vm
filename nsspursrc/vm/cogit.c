/* Automatically generated by
	Cogit VMMaker.oscog-eem.2535 uuid: e4217d2b-77f4-4947-ad0a-eabe9fa6b911
 */

#if defined(__ARM_ARCH_5__) || defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_7__) || defined(__arm__) || defined(__arm32__) || defined(ARM32) || defined(_M_ARM)

#	include "cogitARMv5.c"

#elif defined(_M_I386) || defined(_M_IX86) || defined(_X86_) || defined(i386) || defined(i486) || defined(i586) || defined(i686) || defined(__i386__) || defined(__386__) || defined(X86) || defined(I386)

#	include "cogitIA32.c"

#elif defined(__MIPSEL__)

#	include "cogitMIPSEL.c"

#else
#	error As yet no Cogit implementation appears to exist for your platform.
#	error Consider implementing it, starting by adding a subclass of CogAbstractInstruction.
#endif
