def to_rna(dna_strand):
    rna_strand = bytearray(dna_strand.encode())
    for i in range(len(dna_strand)):
        match rna_strand[i]:
            case 0x41:
                rna_strand[i] = 0x55
            case 0x43:
                rna_strand[i] = 0x47
            case 0x47:
                rna_strand[i] = 0x43
            case 0x54:
                rna_strand[i] = 0x41
    return rna_strand.decode()