/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.2586 uuid: ae4e24e7-dc65-411b-9f81-53f66f183eaf
   from
	GdbARMv8Plugin Cog-eem.362 uuid: 56b23f69-de8f-4323-b39d-62264bcb85f0
 */
static char __buildInfo[] = "GdbARMv8Plugin Cog-eem.362 uuid: 56b23f69-de8f-4323-b39d-62264bcb85f0 " __DATE__ ;



#include "config.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
#endif

#include "GdbARMv8Plugin.h"
#include "sqMemoryAccess.h"


/*** Constants ***/
#define PrimErrBadArgument 3
#define PrimErrBadReceiver 2
#define PrimErrInappropriate 6
#define PrimErrNoMemory 9


/*** Function Prototypes ***/
static void forceStopOnInterrupt(void);
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveDisassembleAtInMemory(void);
EXPORT(sqInt) primitiveErrorAndLog(void);
EXPORT(sqInt) primitiveFlushICacheFromTo(void);
EXPORT(sqInt) primitiveNewCPU(void);
EXPORT(sqInt) primitiveResetCPU(void);
EXPORT(sqInt) primitiveRunInMemoryMinAddressMaxAddressReadWrite(void);
EXPORT(sqInt) primitiveRunInMemoryMinimumAddressReadWrite(void);
EXPORT(sqInt) primitiveSingleStepInMemoryMinAddressMaxAddressReadWrite(void);
EXPORT(sqInt) primitiveSingleStepInMemoryMinimumAddressReadWrite(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);
static sqInt sizeField(sqInt rcvr);
static sqInt sqAssert(sqInt aBool);
static sqInt startOfData(sqInt rcvr);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static void * (*arrayValueOf)(sqInt oop);
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classArray)(void);
static sqInt (*classString)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*getInterruptPending)(void);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*integerObjectOf)(sqInt value);
static sqInt (*isPositiveMachineIntegerObject)(sqInt oop);
static sqInt (*isWordsOrBytes)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*popRemappableOop)(void);
static sqInt (*positive32BitIntegerFor)(unsigned int integerValue);
static usqInt (*positive32BitValueOf)(sqInt oop);
static sqInt (*positive64BitIntegerFor)(usqLong integerValue);
static usqLong (*positive64BitValueOf)(sqInt oop);
static sqInt (*primitiveFail)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*pushRemappableOop)(sqInt oop);
static void (*(*setInterruptCheckChain)(void (*aFunction)(void)))() ;
static sqInt (*stackValue)(sqInt offset);
static sqInt (*storePointerofObjectwithValue)(sqInt index, sqInt oop, sqInt valuePointer);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern void * arrayValueOf(sqInt oop);
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classArray(void);
extern sqInt classString(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt getInterruptPending(void);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt integerObjectOf(sqInt value);
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 15)
extern sqInt isPositiveMachineIntegerObject(sqInt oop);
#else
# define isPositiveMachineIntegerObject(oop) 0
#endif
extern sqInt isWordsOrBytes(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt popRemappableOop(void);
extern sqInt positive32BitIntegerFor(unsigned int integerValue);
extern usqInt positive32BitValueOf(sqInt oop);
extern sqInt positive64BitIntegerFor(usqLong integerValue);
extern usqLong positive64BitValueOf(sqInt oop);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt pushRemappableOop(sqInt oop);
extern void (*setInterruptCheckChain(void (*aFunction)(void)))() ;
extern sqInt stackValue(sqInt offset);
extern sqInt storePointerofObjectwithValue(sqInt index, sqInt oop, sqInt valuePointer);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"GdbARMv8Plugin Cog-eem.362 (i)"
#else
	"GdbARMv8Plugin Cog-eem.362 (e)"
#endif
;


	/* ProcessorSimulatorPlugin>>#forceStopOnInterrupt */
static void
forceStopOnInterrupt(void)
{
	if (getInterruptPending()) {
		forceStopRunning();
	}
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Integer> */
/*	<Bitmap|ByteArray|WordArray> */
/*	Return an Array of the instruction length and its decompilation as a
	string for the instruction at address in memory.
 */

	/* ProcessorSimulatorPlugin>>#primitiveDisassembleAt:InMemory: */
EXPORT(sqInt)
primitiveDisassembleAtInMemory(void)
{
	usqIntptr_t address;
	void *cpu;
	sqInt cpuAlien;
	sqInt instrLenOrErr;
	char *log;
	long logLen;
	sqInt logObj;
	char *logObjData;
	char *memory;
	sqInt resultObj;

	logLen = 0;
	if (!((isPositiveMachineIntegerObject(stackValue(1)))
		 && (isWordsOrBytes(stackValue(0))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	address = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(1))
		: positive64BitValueOf(stackValue(1)));
	memory = ((char *) (firstIndexableField(stackValue(0))));
	cpuAlien = stackValue(2);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		primitiveFailFor(PrimErrBadReceiver);
		return null;
	}
	instrLenOrErr = disassembleForAtInSize(cpu, address, memory, byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize)));
	if (instrLenOrErr < 0) {
		primitiveFailFor(PrimErrInappropriate);
		return null;
	}
	log = getlog((&logLen));
	resultObj = instantiateClassindexableSize(classArray(), 2);
	if (resultObj == 0) {
		primitiveFailFor(PrimErrNoMemory);
		return null;
	}
	pushRemappableOop(resultObj);
	logObj = instantiateClassindexableSize(classString(), logLen);
	if (failed()) {
		popRemappableOop();
		primitiveFailFor(PrimErrNoMemory);
		return null;
	}
	logObjData = arrayValueOf(logObj);
	memcpy(logObjData, log, logLen);
	resultObj = popRemappableOop();
	storePointerofObjectwithValue(0, resultObj, integerObjectOf(instrLenOrErr));
	storePointerofObjectwithValue(1, resultObj, logObj);
	if (!(failed())) {
		popthenPush(3, resultObj);
	}
	return null;
}

	/* ProcessorSimulatorPlugin>>#primitiveErrorAndLog */
EXPORT(sqInt)
primitiveErrorAndLog(void)
{
	char *log;
	long logLen;
	sqInt logObj;
	char *logObjData;
	sqInt resultObj;

	logLen = 0;
	log = getlog((&logLen));
	resultObj = instantiateClassindexableSize(classArray(), 2);
	if (resultObj == 0) {
		primitiveFailFor(PrimErrNoMemory);
		return null;
	}
	storePointerofObjectwithValue(0, resultObj, integerObjectOf(errorAcorn()));
	if (logLen > 0) {
		pushRemappableOop(resultObj);
		logObj = instantiateClassindexableSize(classString(), logLen);
		if (failed()) {
			popRemappableOop();
			primitiveFailFor(PrimErrNoMemory);
			return null;
		}
		resultObj = popRemappableOop();
		logObjData = arrayValueOf(logObj);
		memcpy(logObjData, log, logLen);
		storePointerofObjectwithValue(1, resultObj, logObj);
	}
	popthenPush(1, resultObj);
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Integer> */
/*	<Integer> */
/*	Flush the icache in the requested range */

	/* ProcessorSimulatorPlugin>>#primitiveFlushICacheFrom:To: */
EXPORT(sqInt)
primitiveFlushICacheFromTo(void)
{
	void *cpu;
	sqInt cpuAlien;
	usqIntptr_t endAddress;
	usqIntptr_t startAddress;

	if (!((isPositiveMachineIntegerObject(stackValue(1)))
		 && (isPositiveMachineIntegerObject(stackValue(0))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	startAddress = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(1))
		: positive64BitValueOf(stackValue(1)));
	endAddress = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(0))
		: positive64BitValueOf(stackValue(0)));
	cpuAlien = stackValue(2);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		primitiveFailFor(PrimErrBadReceiver);
		return null;
	}
	flushICacheFromTo(cpu, startAddress, endAddress);
	if (!(failed())) {
		pop(2);
	}
	return null;
}

	/* ProcessorSimulatorPlugin>>#primitiveNewCPU */
EXPORT(sqInt)
primitiveNewCPU(void)
{
	void *cpu;

	cpu = newCPU();
	if (cpu == 0) {
		primitiveFail();
		return null;
	}
	popthenPush(1, (BytesPerWord == 8
		? positive64BitIntegerFor(((usqIntptr_t) cpu))
		: positive32BitIntegerFor(((usqIntptr_t) cpu))));
	return null;
}

	/* ProcessorSimulatorPlugin>>#primitiveResetCPU */
EXPORT(sqInt)
primitiveResetCPU(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maybeErr;

	cpuAlien = stackValue(0);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		primitiveFailFor(PrimErrBadReceiver);
		return null;
	}
	maybeErr = resetCPU(cpu);
	if (maybeErr != 0) {
		primitiveFailFor(PrimErrInappropriate);
		return null;
	}
	if (!(failed())) {
		popthenPush(1, cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	<Integer> */
/*	Run the cpu using the first argument as the memory and the following
	arguments defining valid addresses, running until it halts or hits an
	exception. 
 */

	/* ProcessorSimulatorPlugin>>#primitiveRunInMemory:minimumAddress:maximumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveRunInMemoryMinAddressMaxAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	usqIntptr_t maxAddress;
	sqInt maybeErr;
	char *memory;
	sqInt memorySize;
	usqIntptr_t minAddress;
	usqIntptr_t minWriteMaxExecAddress;

	if (!((isWordsOrBytes(stackValue(3)))
		 && ((isPositiveMachineIntegerObject(stackValue(2)))
		 && ((isPositiveMachineIntegerObject(stackValue(1)))
		 && (isPositiveMachineIntegerObject(stackValue(0))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	memory = ((char *) (firstIndexableField(stackValue(3))));
	minAddress = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(2))
		: positive64BitValueOf(stackValue(2)));
	maxAddress = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(1))
		: positive64BitValueOf(stackValue(1)));
	minWriteMaxExecAddress = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(0))
		: positive64BitValueOf(stackValue(0)));
	cpuAlien = stackValue(4);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		primitiveFailFor(PrimErrBadReceiver);
		return null;
	}
	prevInterruptCheckChain = setInterruptCheckChain(forceStopOnInterrupt);
	if (prevInterruptCheckChain == (forceStopOnInterrupt)) {
		prevInterruptCheckChain = 0;
	}
	memorySize = byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize));
	maybeErr = runCPUInSizeMinAddressReadWrite(cpu, memory, ((memorySize < maxAddress) ? memorySize : maxAddress), minAddress, minWriteMaxExecAddress);
	setInterruptCheckChain(prevInterruptCheckChain);
	if (maybeErr != 0) {
		primitiveFailFor(PrimErrInappropriate);
		return null;
	}
	if (!(failed())) {
		popthenPush(5, cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	Run the cpu using the first argument as the memory and the following
	arguments defining valid addresses, running until it halts or hits an
	exception. 
 */

	/* ProcessorSimulatorPlugin>>#primitiveRunInMemory:minimumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveRunInMemoryMinimumAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maybeErr;
	char *memory;
	usqIntptr_t minAddress;
	usqIntptr_t minWriteMaxExecAddress;

	if (!((isWordsOrBytes(stackValue(2)))
		 && ((isPositiveMachineIntegerObject(stackValue(1)))
		 && (isPositiveMachineIntegerObject(stackValue(0)))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	memory = ((char *) (firstIndexableField(stackValue(2))));
	minAddress = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(1))
		: positive64BitValueOf(stackValue(1)));
	minWriteMaxExecAddress = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(0))
		: positive64BitValueOf(stackValue(0)));
	cpuAlien = stackValue(3);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		primitiveFailFor(PrimErrBadReceiver);
		return null;
	}
	prevInterruptCheckChain = setInterruptCheckChain(forceStopOnInterrupt);
	if (prevInterruptCheckChain == (forceStopOnInterrupt)) {
		prevInterruptCheckChain = 0;
	}
	maybeErr = runCPUInSizeMinAddressReadWrite(cpu, memory, byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize)), minAddress, minWriteMaxExecAddress);
	setInterruptCheckChain(prevInterruptCheckChain);
	if (maybeErr != 0) {
		primitiveFailFor(PrimErrInappropriate);
		return null;
	}
	if (!(failed())) {
		popthenPush(4, cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	<Integer> */
/*	Single-step the cpu using the first argument as the memory and the
	following arguments defining valid addresses.
 */

	/* ProcessorSimulatorPlugin>>#primitiveSingleStepInMemory:minimumAddress:maximumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveSingleStepInMemoryMinAddressMaxAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	usqIntptr_t maxAddress;
	sqInt maybeErr;
	char *memory;
	sqInt memorySize;
	usqIntptr_t minAddress;
	usqIntptr_t minWriteMaxExecAddress;

	if (!((isWordsOrBytes(stackValue(3)))
		 && ((isPositiveMachineIntegerObject(stackValue(2)))
		 && ((isPositiveMachineIntegerObject(stackValue(1)))
		 && (isPositiveMachineIntegerObject(stackValue(0))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	memory = ((char *) (firstIndexableField(stackValue(3))));
	minAddress = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(2))
		: positive64BitValueOf(stackValue(2)));
	maxAddress = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(1))
		: positive64BitValueOf(stackValue(1)));
	minWriteMaxExecAddress = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(0))
		: positive64BitValueOf(stackValue(0)));
	cpuAlien = stackValue(4);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		primitiveFailFor(PrimErrBadReceiver);
		return null;
	}
	memorySize = byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize));
	maybeErr = singleStepCPUInSizeMinAddressReadWrite(cpu, memory, ((memorySize < maxAddress) ? memorySize : maxAddress), minAddress, minWriteMaxExecAddress);
	if (maybeErr != 0) {
		primitiveFailFor(PrimErrInappropriate);
		return null;
	}
	if (!(failed())) {
		popthenPush(5, cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	Single-step the cpu using the first argument as the memory and the
	following arguments defining valid addresses.
 */

	/* ProcessorSimulatorPlugin>>#primitiveSingleStepInMemory:minimumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveSingleStepInMemoryMinimumAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maybeErr;
	char *memory;
	usqIntptr_t minAddress;
	usqIntptr_t minWriteMaxExecAddress;

	if (!((isWordsOrBytes(stackValue(2)))
		 && ((isPositiveMachineIntegerObject(stackValue(1)))
		 && (isPositiveMachineIntegerObject(stackValue(0)))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	memory = ((char *) (firstIndexableField(stackValue(2))));
	minAddress = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(1))
		: positive64BitValueOf(stackValue(1)));
	minWriteMaxExecAddress = (BytesPerOop == 4
		? positive32BitValueOf(stackValue(0))
		: positive64BitValueOf(stackValue(0)));
	cpuAlien = stackValue(3);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		primitiveFailFor(PrimErrBadReceiver);
		return null;
	}
	maybeErr = singleStepCPUInSizeMinAddressReadWrite(cpu, memory, byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize)), minAddress, minWriteMaxExecAddress);
	if (maybeErr != 0) {
		primitiveFailFor(PrimErrInappropriate);
		return null;
	}
	if (!(failed())) {
		popthenPush(4, cpuAlien);
	}
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine *anInterpreter)
{
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		arrayValueOf = interpreterProxy->arrayValueOf;
		byteSizeOf = interpreterProxy->byteSizeOf;
		classArray = interpreterProxy->classArray;
		classString = interpreterProxy->classString;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		getInterruptPending = interpreterProxy->getInterruptPending;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		integerObjectOf = interpreterProxy->integerObjectOf;
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 15)
		isPositiveMachineIntegerObject = interpreterProxy->isPositiveMachineIntegerObject;
#else
#if !defined(isPositiveMachineIntegerObject)
		isPositiveMachineIntegerObject = 0;
#endif
#endif
		isWordsOrBytes = interpreterProxy->isWordsOrBytes;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		popRemappableOop = interpreterProxy->popRemappableOop;
		positive32BitIntegerFor = interpreterProxy->positive32BitIntegerFor;
		positive32BitValueOf = interpreterProxy->positive32BitValueOf;
		positive64BitIntegerFor = interpreterProxy->positive64BitIntegerFor;
		positive64BitValueOf = interpreterProxy->positive64BitValueOf;
		primitiveFail = interpreterProxy->primitiveFail;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		pushRemappableOop = interpreterProxy->pushRemappableOop;
		setInterruptCheckChain = interpreterProxy->setInterruptCheckChain;
		stackValue = interpreterProxy->stackValue;
		storePointerofObjectwithValue = interpreterProxy->storePointerofObjectwithValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


/*	Answer the first field of rcvr which is assumed to be an Alien of at least
	8 bytes
 */

	/* ProcessorSimulatorPlugin>>#sizeField: */
static sqInt
sizeField(sqInt rcvr)
{
	return longAt(rcvr + BaseHeaderSize);
}

	/* SmartSyntaxInterpreterPlugin>>#sqAssert: */
static sqInt
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
	return aBool;
}


/*	<Alien oop> ^<Integer> */
/*	Answer the start of rcvr's data. For direct aliens this is the address of
	the second field. For indirect and pointer aliens it is what the second
	field points to. */

	/* ProcessorSimulatorPlugin>>#startOfData: */
static sqInt
startOfData(sqInt rcvr)
{
	return ((longAt(rcvr + BaseHeaderSize)) > 0
		? (rcvr + BaseHeaderSize) + BytesPerOop
		: longAt((rcvr + BaseHeaderSize) + BytesPerOop));
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "GdbARMv8Plugin";
void* GdbARMv8Plugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveDisassembleAtInMemory\000\000", (void*)primitiveDisassembleAtInMemory},
	{(void*)_m, "primitiveErrorAndLog\000\377", (void*)primitiveErrorAndLog},
	{(void*)_m, "primitiveFlushICacheFromTo\000\000", (void*)primitiveFlushICacheFromTo},
	{(void*)_m, "primitiveNewCPU\000\377", (void*)primitiveNewCPU},
	{(void*)_m, "primitiveResetCPU\000\000", (void*)primitiveResetCPU},
	{(void*)_m, "primitiveRunInMemoryMinAddressMaxAddressReadWrite\000\000", (void*)primitiveRunInMemoryMinAddressMaxAddressReadWrite},
	{(void*)_m, "primitiveRunInMemoryMinimumAddressReadWrite\000\000", (void*)primitiveRunInMemoryMinimumAddressReadWrite},
	{(void*)_m, "primitiveSingleStepInMemoryMinAddressMaxAddressReadWrite\000\000", (void*)primitiveSingleStepInMemoryMinAddressMaxAddressReadWrite},
	{(void*)_m, "primitiveSingleStepInMemoryMinimumAddressReadWrite\000\000", (void*)primitiveSingleStepInMemoryMinimumAddressReadWrite},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveDisassembleAtInMemoryAccessorDepth = 0;
signed char primitiveFlushICacheFromToAccessorDepth = 0;
signed char primitiveResetCPUAccessorDepth = 0;
signed char primitiveRunInMemoryMinAddressMaxAddressReadWriteAccessorDepth = 0;
signed char primitiveRunInMemoryMinimumAddressReadWriteAccessorDepth = 0;
signed char primitiveSingleStepInMemoryMinAddressMaxAddressReadWriteAccessorDepth = 0;
signed char primitiveSingleStepInMemoryMinimumAddressReadWriteAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */