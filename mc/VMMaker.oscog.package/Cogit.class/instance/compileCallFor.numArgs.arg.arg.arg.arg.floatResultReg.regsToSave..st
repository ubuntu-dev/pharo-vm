initialization
compileCallFor: aRoutine numArgs: numArgs arg: regOrConst0 arg: regOrConst1 arg: regOrConst2 arg: regOrConst3 floatResultReg: resultRegOrNone regsToSave: regMask
	"Generate a call to aRoutine with up to 4 arguments.  If resultRegOrNone is not
	 NoReg assign the C result to resultRegOrNone.  If saveRegs, save all registers.
	 Hack: a negative arg value indicates an abstract register, a non-negative value
	 indicates a constant."
	<var: #aRoutine type: #'void *'>
	<inline: false>
	| regsToSave |
	regsToSave := resultRegOrNone = NoReg
						ifTrue: [regMask]
						ifFalse: [regMask bitClear: (self registerMaskFor: resultRegOrNone)].
	cStackAlignment > objectMemory wordSize ifTrue:
		[backEnd
			genAlignCStackSavingRegisters: regsToSave
			numArgs: numArgs
			wordAlignment: cStackAlignment / objectMemory wordSize].
	backEnd
		genSaveRegs: regsToSave;
		genMarshallNArgs: numArgs arg: regOrConst0 arg: regOrConst1 arg: regOrConst2 arg: regOrConst3.
	self CallFullRT: (self cCode: [aRoutine asUnsignedInteger]
						inSmalltalk: [self simulatedTrampolineFor: aRoutine]).
	resultRegOrNone ~= NoReg ifTrue:
		[backEnd cFloatResultToRd: resultRegOrNone].
	 backEnd genRemoveNArgsFromStack: numArgs.
	backEnd genRestoreRegs: regsToSave