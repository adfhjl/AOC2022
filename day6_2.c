#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_SIZE 4096
#define MIN 0
#define MAX 1

// First answer: 3605 V

bool	has_duplicate(const char *str, int len)
{
	int	i = 0;
	int	j;

	while (i + 1 < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	main(void)
{
	// char		input[] = "mjqjpqmgbljsphdztnvjfqwrcgsmlb";
	char		input[INPUT_SIZE] = "pjbjvjtjljplppjssvtvwtwptptztltbtrrjgrjrzrqrjrbrhbrhrlllbpbdbbzqqgsqshqssjjbsjbsbmbhhmchhrqrcqqbwbqwwqrrznnsbswwwdjwdwmmsvszzlbbgddbgdgfgttzjzrjzrjzzvrvqqgpqggtbgtgvvrhvhtvtjjbpjjfjhjbhbddbjjjmzmtmgmpgmmmljlnljjmpmbpmbmrrlhhlppdgdfgfbbqlbbtffjjgvvnpvpbpttqmmnhhgfgrrwhrrbnbznzccmbmvmmzszsvsbvbccsrslsjsbbtdtwtvttvpvzzvbzzwczwcczhzhwhjhjghgppgpgttdwdhwhphnppqmpqqhthcchdhmhnnbcnbcbbggbfblljttwsswspsggpjjzszcscsmcmdmnngzzhrzrbrhbhzbzvzgvgffnlnljlrrhchhsvhssmpmccncdnccgdgbglgtlggnllsvvpfvpfpbffsgglddjrrzzphhptprtppwrwffzllrbrmrpmpdmpdmpplpspcphcphhgmmqnmmvnmmdvmvsmmqjmmlmlbmlbmlltlptphpnncscbscbcggwhhgjgqjqmjmdjmdjdrrvgvvzlldgdnnvttmmpffdjjvvchcwwbhwbwzzlmlccrttcntccpcgccpgcpggdrrbtrthhlrrbqrrpspdsdldbldblbzbpbgggtngtgqqtwwdjjmmcrmcrcvclcddhllpzpdzzmccrtccfvffccfhccpscctbbbzqzvvllgwlgwgvwwjswjswsvvwhhvjvsjvjmmjhjrhrmrvrnrccmnmzzmdzzbtbvbqvvgzgcgvvvvlltvllbfbqqrppwhpwpffzddzdzwdzzrggmhmfhmhbbzjzsjzzhhjdhhdnndsnssnfffbmffwhwrhhmmbnnbrnrbrrtqtztnzzzzblbhbdhbbfmfqfmmsgszzvfzfmfwfnwfwggwngnqnwqnwqwvwqvwvdvrvjjfnjnmnfmmwzzltztjjqnnnmlmzlmmrcmclcqqhrhdhccdfdvfvccvtcvvdmmtmccwjjcbcrrjmrjrdrffgwwvbvlvsspwpsspzsschssmqsqmqmlqmmqgqfqcqjcjtthjttlddfvvwwjvvtpvvfsvffqnffznzqzszgzmmjttwztwzzhqqccqsqmqnmqqjhqhzhwhvhdddsndsdfftvffwlwnnmmdpmmnhhrqrrclcdlcddhcdcppgrprnpnptnpphgpbqfngdgzvgndwcgrwcsfmhzsvddhzbgjmvvdjjzswvgnpmvgdpwsgbgjzjpsrfdzdzjzzrpplbhsmgddqzjbdzdzltqqwqjzqvwfmcdppbdbprrwzhmnrqclzrnmdjnfbwmvdrwtpwvgscrqgpndqnzbjsbljcbthbpgdjdcdwfhpvjnbsfjdlrjldvvmtfdslrhlfwmvclqrljrqmmjgqfwmfgwdjzzptgcthvtgdswsqjrqvnzmtqldjjcqnfhtvbwhjqlvpptfwjrdpcwvzddgcjzvqbhtsnnnjqqmqlbgvqmvjhvvpbzcbdmhgmcjbfcccsvlzjztvjzrrlhtgwccdcgcptqlmdhmdhvqzfntbjqtsmvqgwsltqntgszllntrljfgfsghtbbcqrdgwqphmbqtzmjqccrgvqpqpchzjstdmmtvntwjqsbcqjgnhzlllcfbpgtgrhwwhqqdlgrlsbzbmchvjnsgpdnmqvtgwqjpgflqgfngjfcfwqzmvvgzmmhbgfnbzvzclwclqdcccgbrrzpwdtprgsvhbgsnbntgrvnzhrnzfzdmnlbnrbqvmjbwpgvjlhbcvsrlqmcsnlrvtfdwtvcbmlndgbctsnmtctjszlpddqmzbtphhhfznwbdfsgppmdmczmhmmrzpllfqqbgvlsrscpfgznhdhgrnnnvrchgvzlqbgvcfghjvlvrvpclfcshbmvglcfrjbzrbcjmjjrfgqthwfrqbgtjldmbnfwllspmwrvstvrltvrlvrtjvprgtgzjlrgclvjhqpfcwcdbdtzwdsdfrtsvtvgjmsszdfqlmhqqlzswjfndswlmhcrhglphvpnfjpbmggbwlmzjchpnrllbjpmgmzjjrqpqgsbrszqhdljcpnclvrvbntgtcdcmhtdhgslhpvdjpvrszfrjhsbvcvtfwvvgczprnpbhmnnlmctbtqdjspgvhvnhwvspwgnjvzllwlnjhfjwsslppmjbfbdnthcpzbcmnnbvhctgwgdvhvlrbltmdnlfcsncqgrmjprshdvvtvcccgzhszcjgczhmhtvmccjpchqshhdzjjhbfpzqdjszdhdvlmgctmwcjprwlsqbcqhlcrfdgnqzfdfvqslmqlppbsvbmjmfbrtdmpmtqvwvppcfzddjzhhzlrrnnhbrlhmzlqwftprfvctnfhfhfzrnrvggfqmqwcwszhtbfjncprgwcqbjlvtnrprlwwghswvprjmsbmqvwnnfggprndvshfvvwtrqjpwghgbppftgzhqjslfzhngwfsjnmjzdsjqgpmglwnjlcgmczgvndszrszcpnzqpbzjmgrfsbjlghwrbqsqdhlnhzsvsgbqhbcdffjlgrbdrrjvclzqpftlhdvvcrvlgvlpnjcqdcbdjtlwnldjhhhzrwsqlhlsztwrznfsszptlrhjmqwmnfwjtjwmmmtvwzhpmjgzgsscbddgvvhpcnhvnggzhbzvvjlmdftpbcsvtsttrvgghptmmcdclbdvmnsdntthfbdznbclwccnlzcvdwzrqgddjszvbdqcjppzrtpnrhfcvvwpjqczgqwzzzvzmlnlzqszvtllftthgwgftjzsndpzzcnqpcvmsdvvfrjdsvfclsqqhsjrrctfvdrlhfmhprjggdcmqrrbqtwnrllhhztvjgmzqszbvqfwsgllvhsvfrjffvdscwjzqlzlwdpgthddpgzjfdbdqpsnntwpslvsdpqfnsgcllszcjwvtqhwhpfrlfdgwrfmgfpjmvnstrmtfcvgwlqdfqvntltqtrmjjtwcthvwntqgvncssplnmvlnstlcphvlcmvjnstwldtntchcbmzmlzhgjfbrdlgzvqpgcndmfdnmcnwhmpdnpqstfddddcrpgrpfwfbzjqtnzwwqpzrqpmrjpfznrndfgwhtlvrcrphqfjzjbttwhgnsngqwvnsbvcqtjlmhvmnmnnmjcmlpnpgmrqsbmgljvsfqvrlljqzmzqqbgpvcrwdjmgsglssjswmnvtshhfqjhqmfmvcjwfpwsppgtrqsbhhcdljnjphnjszqpvdplbwzpwmmpwfhmhngtllzqvpmgdctmfqwwqjszssmjhwnrjdtmmvpdnwlqtcbpfcmwtbjmmsmmdpqgzdhsblgjmjbpzgqvqhnggtwmhztbbhlflllgwblncjjsngdgvsfdmsbsvlpnjjzqqbzhsqclmjnnmmwlpvtgwqmcgmrqdwdddlgbvhntbztbjnqhdlggnzwsdtdzprgddhtcttjrcpszgchtfwqjsdlnbntfwqpzpfsqrqjhthmcfszwtwcqwbvfzdnrrpmzjdrhsgmhfbsldvcrjdwvpqpszzlvbptljgvccqsdhhnztjpghbvhfptgplqdvldjzfthpspwvgljwnnndwrqzbrstnqbvrrcghssnrpvtrhmvcmbngwndzfswmgjwnnzqdcjhpthcgvthsnwqzrnzrvdjmctchhsbnrtvctzqfpcjhzmhnfjlqftbjztfbcppgmwvrzzrvlcpnpwwpvtcpdplrcfpgfqjtlfjtphhpcltwqcbqbznbtjrtdrpgtvzmgsclhpptrssqqbctdrftqzmwjmrmjtgmjmsnbnspjvcqpqnmgzgjrmfhghvsfsdqnbdjsbcpczsdswdcvhfzlgpzbtmztcnbpcvjnlcdmmlbtwzsfqtfnlrwjtwmgslcgptgbdsfwdhppvfwbbgdfdqtrbncbznmqtchzsdzlhlhjnnbpdvnnfjrdfbdqmvcb";
	int			i = 0;


	printf(	"---------------------------\n"
			"Advent of Code 2022: Day 6 Part Two!\n"
			"---------------------------\n");
	while (input[i] != '\0')
	{
		if (!has_duplicate(&input[i], 14))
		{
			printf("Found string %*s\n", i + 1, input);
			break ;
		}
		i++;
	}
	printf("%i is the answer\n", i + 14);
	return (0);
}
