inline primitive generators generated code
genLowcodeLoadArgumentInt32
	<option: #LowcodeVM>
	<inline: true>
	"Generated by the Lowcode instruction generator."
	| value baseOffset |
	baseOffset := extA.
	self allocateRegistersForLowcodeResultInteger: [:valueValue |
		value := valueValue.
	].


	self loadNativeArgumentAddress: baseOffset to: TempReg.
	self MoveM32: 0 r: TempReg R: value.
	self ssPushNativeRegister: value.

	extA := 0.
	^ 0

