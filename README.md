# ArchDismantler
A high-performance disassembler POC. The disassembler's core is structured around the idea of indexing instruction descriptors, which can allow for further indexing of the bytes. The descriptor set can be precompiled before disassembly, the encoding of the instructions is rather lazy, hence why I'd suggest using a separate descriptor compiler for any serious solution (preferably compiling from documentation provided within Intel manual from volumes 2 (general instruction set) to 3 (SMX and VMX instructions)). This project is not to be used as a serious disassembly solution, rather as a reference for ideas on how to handle the parsing of instructions and/or disassembly conversion to IL code.