/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.1325 uuid: a0bb0f7f-5e6e-48a7-bf73-fa5d135e06c0
   from
	HostWindowPlugin VMMaker.oscog-eem.1325 uuid: a0bb0f7f-5e6e-48a7-bf73-fa5d135e06c0
 */
static char __buildInfo[] = "HostWindowPlugin VMMaker.oscog-eem.1325 uuid: a0bb0f7f-5e6e-48a7-bf73-fa5d135e06c0 " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "HostWindowPlugin.h"
#include "sqMemoryAccess.h"


/*** Constants ***/


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveCloseHostWindow(void);
EXPORT(sqInt) primitiveCreateHostWindow(void);
EXPORT(sqInt) primitiveHostWindowPosition(void);
EXPORT(sqInt) primitiveHostWindowPositionSet(void);
EXPORT(sqInt) primitiveHostWindowSize(void);
EXPORT(sqInt) primitiveHostWindowSizeSet(void);
EXPORT(sqInt) primitiveHostWindowTitle(void);
EXPORT(sqInt) primitiveShowHostWindowRect(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*integerObjectOf)(sqInt value);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*isWords)(sqInt oop);
static sqInt (*makePointwithxValueyValue)(sqInt xValue, sqInt yValue);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*primitiveFail)(void);
static sqInt (*slotSizeOf)(sqInt oop);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*success)(sqInt aBoolean);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt integerObjectOf(sqInt value);
extern sqInt isBytes(sqInt oop);
extern sqInt isWords(sqInt oop);
extern sqInt makePointwithxValueyValue(sqInt xValue, sqInt yValue);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt primitiveFail(void);
extern sqInt slotSizeOf(sqInt oop);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern sqInt success(sqInt aBoolean);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"HostWindowPlugin VMMaker.oscog-eem.1325 (i)"
#else
	"HostWindowPlugin VMMaker.oscog-eem.1325 (e)"
#endif
;



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


/*	Close a host window. windowIndex is the SmallInt handle returned
	previously by primitiveCreateHostWindow. Fail if the index is invalid or
	the platform code fails
 */

	/* HostWindowPlugin>>#primitiveCloseHostWindow */
EXPORT(sqInt)
primitiveCloseHostWindow(void)
{
	sqInt ok;
	sqInt windowIndex;

	windowIndex = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	ok = closeWindow(windowIndex);
	if (!ok) {
		primitiveFail();
	}
	if (failed()) {
		return null;
	}
	pop(1);
	return null;
}


/*	Create a host window of width 'w' pixels, height 'h' with the origin of
	the user area at 'x@y' from the topleft corner of the screen.
	Return the SmallInt value of the internal index to the window description
	block - which is whatever the host platform code needs it to be.
 */

	/* HostWindowPlugin>>#primitiveCreateHostWindow */
EXPORT(sqInt)
primitiveCreateHostWindow(void)
{
	sqInt h;
	char *list;
	sqInt listLength;
	sqInt w;
	sqInt windowIndex;
	sqInt x;
	sqInt y;
	sqInt _return_value;

	w = stackIntegerValue(4);
	h = stackIntegerValue(3);
	x = stackIntegerValue(2);
	y = stackIntegerValue(1);
	success(isBytes(stackValue(0)));
	list = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	listLength = slotSizeOf(((sqInt)(long)(list) - BaseHeaderSize));
	windowIndex = createWindowWidthheightoriginXyattrlength(w, h, x, y, list, listLength);
	if (windowIndex > 0) {
		_return_value = integerObjectOf(windowIndex);
		if (failed()) {
			return null;
		}
		popthenPush(6, _return_value);
		return null;
	}
	else {
		primitiveFail();
		return null;
	}
}


/*	Return the origin position of the user area of the window in pixels from
	the topleft corner of the screen. Fail if the windowIndex is invalid or
	the platform routine returns -1 to indicate failure
 */

	/* HostWindowPlugin>>#primitiveHostWindowPosition */
EXPORT(sqInt)
primitiveHostWindowPosition(void)
{
	sqInt pos;
	sqInt windowIndex;
	sqInt _return_value;

	windowIndex = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	pos = ioPositionOfWindow(windowIndex);
	if (pos == -1) {
		primitiveFail();
		return null;
	}
	else {
		_return_value = makePointwithxValueyValue(((usqInt) pos) >> 16, pos & 0xFFFF);
		if (failed()) {
			return null;
		}
		popthenPush(2, _return_value);
		return null;
	}
}


/*	Set the origin position of the user area of the window in pixels from the
	topleft corner of the screen- return the position actually set by the
	OS/GUI/window manager. Fail if the windowIndex is invalid or the platform
	routine returns -1 to indicate failure
 */

	/* HostWindowPlugin>>#primitiveHostWindowPositionSet */
EXPORT(sqInt)
primitiveHostWindowPositionSet(void)
{
	sqInt pos;
	sqInt windowIndex;
	sqInt x;
	sqInt y;
	sqInt _return_value;

	windowIndex = stackIntegerValue(2);
	x = stackIntegerValue(1);
	y = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	pos = ioPositionOfWindowSetxy(windowIndex, x, y);
	if (pos == -1) {
		primitiveFail();
		return null;
	}
	else {
		_return_value = makePointwithxValueyValue(((usqInt) pos) >> 16, pos & 0xFFFF);
		if (failed()) {
			return null;
		}
		popthenPush(4, _return_value);
		return null;
	}
}


/*	Return the size of the user area of the window in pixels. Fail if the
	windowIndex is invalid or the platform routine returns -1 to indicate
	failure 
 */

	/* HostWindowPlugin>>#primitiveHostWindowSize */
EXPORT(sqInt)
primitiveHostWindowSize(void)
{
	sqInt size;
	sqInt windowIndex;
	sqInt _return_value;

	windowIndex = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	size = ioSizeOfWindow(windowIndex);
	if (size == -1) {
		primitiveFail();
		return null;
	}
	else {
		_return_value = makePointwithxValueyValue(((usqInt) size) >> 16, size & 0xFFFF);
		if (failed()) {
			return null;
		}
		popthenPush(2, _return_value);
		return null;
	}
}


/*	Set the size of the user area of the window in pixels - return what is
	actually set by the OS/GUI/window manager. Fail if the windowIndex is
	invalid or the platform routine returns -1 to indicate failure
 */

	/* HostWindowPlugin>>#primitiveHostWindowSizeSet */
EXPORT(sqInt)
primitiveHostWindowSizeSet(void)
{
	sqInt size;
	sqInt windowIndex;
	sqInt x;
	sqInt y;
	sqInt _return_value;

	windowIndex = stackIntegerValue(2);
	x = stackIntegerValue(1);
	y = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	size = ioSizeOfWindowSetxy(windowIndex, x, y);
	if (size == -1) {
		primitiveFail();
		return null;
	}
	else {
		_return_value = makePointwithxValueyValue(((usqInt) size) >> 16, size & 0xFFFF);
		if (failed()) {
			return null;
		}
		popthenPush(4, _return_value);
		return null;
	}
}


/*	Set the title bar label of the window. Fail if the windowIndex is invalid
	or the platform routine returns -1 to indicate failure
 */

	/* HostWindowPlugin>>#primitiveHostWindowTitle */
EXPORT(sqInt)
primitiveHostWindowTitle(void)
{
	sqInt id;
	sqInt res;
	sqInt titleLength;
	char *titleString;

	id = stackIntegerValue(1);
	success(isBytes(stackValue(0)));
	titleString = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	titleLength = slotSizeOf(((sqInt)(long)(titleString) - BaseHeaderSize));
	res = ioSetTitleOfWindow(id, titleString, titleLength);
	if (res == -1) {
		primitiveFail();
	}
	if (failed()) {
		return null;
	}
	pop(2);
	return null;
}


/*	Host window analogue of DisplayScreen> primShowRectLeft:right:top:bottom:
	(Interpreter>primitiveShowDisplayRect) which takes the window index,
	bitmap details and the rectangle bounds. Fail if the windowIndex is
	invalid or the
	platform routine returns false to indicate failure
 */

	/* HostWindowPlugin>>#primitiveShowHostWindowRect */
EXPORT(sqInt)
primitiveShowHostWindowRect(void)
{
	sqInt bottom;
	sqInt d;
	unsigned *dispBits;
	sqInt h;
	sqInt left;
	sqInt ok;
	sqInt right;
	sqInt top;
	sqInt w;
	sqInt windowIndex;

	windowIndex = stackIntegerValue(8);
	success(isWords(stackValue(7)));
	dispBits = ((unsigned *) (firstIndexableField(stackValue(7))));
	w = stackIntegerValue(6);
	h = stackIntegerValue(5);
	d = stackIntegerValue(4);
	left = stackIntegerValue(3);
	right = stackIntegerValue(2);
	top = stackIntegerValue(1);
	bottom = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	ok = ioShowDisplayOnWindow(dispBits, w, h, d, left, right, top,
bottom, windowIndex);
	if (!ok) {
		primitiveFail();
	}
	if (failed()) {
		return null;
	}
	pop(9);
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		integerObjectOf = interpreterProxy->integerObjectOf;
		isBytes = interpreterProxy->isBytes;
		isWords = interpreterProxy->isWords;
		makePointwithxValueyValue = interpreterProxy->makePointwithxValueyValue;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		primitiveFail = interpreterProxy->primitiveFail;
		slotSizeOf = interpreterProxy->slotSizeOf;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackValue = interpreterProxy->stackValue;
		success = interpreterProxy->success;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


/*	do any window related VM closing down work your platform requires. */

	/* HostWindowPlugin>>#shutdownModule */
EXPORT(sqInt)
shutdownModule(void)
{
	return ioCloseAllWindows();
}

	/* SmartSyntaxInterpreterPlugin>>#sqAssert: */
static sqInt
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* HostWindowPlugin_exports[][3] = {
	{"HostWindowPlugin", "getModuleName", (void*)getModuleName},
	{"HostWindowPlugin", "primitiveCloseHostWindow\000\000", (void*)primitiveCloseHostWindow},
	{"HostWindowPlugin", "primitiveCreateHostWindow\000\000", (void*)primitiveCreateHostWindow},
	{"HostWindowPlugin", "primitiveHostWindowPosition\000\000", (void*)primitiveHostWindowPosition},
	{"HostWindowPlugin", "primitiveHostWindowPositionSet\000\000", (void*)primitiveHostWindowPositionSet},
	{"HostWindowPlugin", "primitiveHostWindowSize\000\000", (void*)primitiveHostWindowSize},
	{"HostWindowPlugin", "primitiveHostWindowSizeSet\000\000", (void*)primitiveHostWindowSizeSet},
	{"HostWindowPlugin", "primitiveHostWindowTitle\000\000", (void*)primitiveHostWindowTitle},
	{"HostWindowPlugin", "primitiveShowHostWindowRect\000\000", (void*)primitiveShowHostWindowRect},
	{"HostWindowPlugin", "setInterpreter", (void*)setInterpreter},
	{"HostWindowPlugin", "shutdownModule\000\377", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveCloseHostWindowAccessorDepth = 0;
signed char primitiveCreateHostWindowAccessorDepth = 0;
signed char primitiveHostWindowPositionAccessorDepth = 0;
signed char primitiveHostWindowPositionSetAccessorDepth = 0;
signed char primitiveHostWindowSizeAccessorDepth = 0;
signed char primitiveHostWindowSizeSetAccessorDepth = 0;
signed char primitiveHostWindowTitleAccessorDepth = 0;
signed char primitiveShowHostWindowRectAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */