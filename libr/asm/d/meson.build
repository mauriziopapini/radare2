sdb_files = [
  '6502',
  '8051',
  'LH5801', ## todo lowercase
  'stm8',
  'arc',
  'arm',
  'avr',
  'bf',
  'bpf',
  'chip8',
  'dalvik',
  'evm',
  'gb',
  'i4004',
  'i8080',
  'java',
  'lm32',
  'm68k',
  'mips',
  'msp430',
  'pic18c',
  'pickle',
  'ppc',
  'propeller',
  'riscv',
  's390',
  'sh',
  'sparc',
  'tms320',
  'tricore',
  'v810',
  'v850',
  'x86',
  'xtensa',
  'z80',
]

r_asm_d_sources = []
foreach file : sdb_files
  if get_option('sdb_cgen')
    outfile = '@0@.c'.format(file)
    gen_cmd = sdb_gen_cmd_cgen
  else
    outfile = '@0@.sdb'.format(file)
    gen_cmd = sdb_gen_cmd
  endif
  r_asm_d_sources += custom_target(outfile,
    input: '@0@.sdb.txt'.format(file),
    output: outfile,
    command: gen_cmd,
    depends: sdb_exe,
    build_by_default: true,
    install: true,
    install_dir: join_paths(r2_sdb, 'opcodes')
  )
endforeach
