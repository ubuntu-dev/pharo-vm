gc - global
globalGarbageCollect
	"If we're /not/ a clone, clone the VM and push it over the cliff.
	 If it survives, destroy the clone and continue.  We should be OK until next time."
	parent ifNil:
		[coInterpreter cr; print: 'GC number '; print: statFullGCs; tab; flush.
		 coInterpreter cloneSimulation objectMemory globalGarbageCollect.
		 Smalltalk garbageCollect].
	^super globalGarbageCollect