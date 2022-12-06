#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_SIZE 300

// First answer: 2575 X
// Second answer: 2312 X
// Second answer: 2616 V

size_t	get_priority(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 27);
	return (c - 'a' + 1);
}

int	main(void)
{
	char	*input[INPUT_SIZE] = {
		"dtddvvhwttHJhwdhJPddhwJGppmGjgpQgTjQplQpTljwpg",
		"BfzSzRSVVMVNRMDDNBSNSnfBmbrglGQbmNpQggFjpgpbQlQb",
		"ZSBffLnVZdCCPJjhhL",
		"RGCZpWWWFlHQQbgvFssg",
		"jLnMzjnrnjjNjhrjdwbHscsVVgDVQPvPwh",
		"nfJnLMLzjJMtnjNnnBbZtBWBqqbTTTBRpT",
		"nddlhBtqTBqTVSlBtmCmVcRVmZggfWbcZc",
		"jDjvPrPSNPwrDNRWbbgWCjRRCcWm",
		"DzDwSpFrvrvFPQLzQnsqztBthTJnGJqlsJ",
		"gssGmzwgRgsNmTsqgDnDJnbDHHhhzFdDDh",
		"WQVFjMWrVQrVvVVjVctSSLSMZhnJZPBnbdnhbnHZZBDJBh",
		"VCtcccVQLrfvrSlGmfTfNgfmlFgm",
		"DsmfsBbNNZhDWsbmWmNbbPDHLFjcctjjGcnZGzncnctcGH",
		"SwVQJrjVwpgSVRpjpVRrlTMCFFCLCFFcHzzGMcHrtHHH",
		"ppVwTwSwpwvSlSlJTjVVbPhsvvBssWsNfsqWPvWs",
		"BJwqwJtqqDDDrGDnPFzPFfpphD",
		"TgZscCHQLSHgZcfMzpjFFjzsshfj",
		"LcNlTVQCCVLLZTLNvpRtpvBBvRJmNB",
		"bDBGQBBCTTNPGPPwPzcHfVHrDtLWLVrWVjjHWr",
		"gpssqqsqlMFfLZQWftjVpr",
		"lvqqFMRlFcQvbzCNCG",
		"fhhMDdPhWMJMWvhhSfwRSGlzFbSFNlzw",
		"LcqTCqcgZqjTggVjcwbFRwbDBTzbRGRwTS",
		"cHLpZgnCHpQsDdsmQp",
		"jwStJjJhtgJStpgwJMggQWqQTNTfNTWfbNNMCCNG",
		"zRZnFPRZPVncPGVFRlRmGHCTqfCCPCHHfLfbTQCbTq",
		"lnVmFZRZDnRVBFZcrZlhjpggvppthGhphpwprS",
		"lcttSptHHllQbMcsrltSQGpvNBzpgWBBBDDGWzvgLz",
		"PdjPVRFhFqFjRRCjzvRWnWLBLgbBBLzg",
		"hhCCFbPTmjPdhZjhPhZCmTjjMsrJSfHrcmHJrHHmlcJSsmft",
		"WhWnLZSSnSzQQhfLLNSfmDHrCFDDHtpjGGtTGQCG",
		"gJbJBcMVwJlRRdbwvwJBVtjdtHHTmptpHTCtTFrFCp",
		"JwwgvRMJlvJwgqgvqRMcnWWhLPzzsqfnZWnfWWnj",
		"zdwTSvzHMvVSzDCtZhtGmbTGhm",
		"lcBHfFjjgtsmDCgshD",
		"cJPBnqNFnLfHJFPqljclqJzQvSSVWvSnMwvSzSWWdMWM",
		"pNJMcZrsZDLDcbcccMpQffHqvgdwdFFmdmqwvqmgmzsw",
		"hhnWjTTStRCGSMgvvgvdqvdFjvVz",
		"hCTSWhPGttTCGBWMRlTCMSnPBDJpbDfDpNpbbNJfJDJbpJpN",
		"lbcQcSNFchhQNqHLLqhLqrMpqM",
		"WfsnsszPWfBBVpHdprrpdnGL",
		"WTzWfwjtTBzwwBDzmfSSQmmbFZcpQNcbZZbv",
		"PwSJSlmtPPgwgmHhPPvRvGHLRLQRBQGCQVGb",
		"rnsFDnnfGGRWQRnW",
		"dfTTfTFdfrfFFFzQFPJPSSlhqtllNPzgwS",
		"MMbTFZrcrGZMDqNStWScDtzS",
		"dvWmhQggQvCnfnqPqDnDjnfP",
		"lgvdvLClWCQlgdhlrMBBHpGlwbHHGH",
		"CQHgQpPdCQpsCpzRwSVRSzRZwZ",
		"JbNBbcbrJvbJnqVznwwTzrzz",
		"wNbfLvvfDNNBHPFLhddFsQss",
		"VVzqvwzpqvzqNVVHGNqjHpNfSQDWdWwJdPWrWccdQrWrrDdd",
		"nLcbtBRtBhcnWSJQlJSgll",
		"tFbLLLRRhMtsBMtRCRsLCMBVjjvHTNjHHjzcvFFppGHzTT",
		"QCPrPWNPlWjGGZqGmvdPGd",
		"JgpHpSfphhfpVmBSgnTvdtddGvZVdvddDv",
		"LhphBfHpSwSwfHcMgfpmBWWWbsNCjFWsljNbbjlLjb",
		"QJmQbRmdfmdSQRQZSJltTltNvTrtDtrlftDD",
		"wpZcHVwwMgBpWMVgWpHLphztDvvGvDPlnGvDLlNrDPnNPl",
		"McgWFWHHHzVpMgZQFqbjsdjqqRCq",
		"JPhLFfMJDLQnjNCvWWpdjjdM",
		"crSwnwVnwSRBcNBNjjWCdC",
		"GlbTGbsSzrtbmbfhnJQP",
		"fDLSWVDRHHfVWHgPcZlDlZbbQhBcZQbb",
		"jrmFmprTpFztmddjdjrpvBQlQZGhQbTsQbGcQbcbQs",
		"nvqdpmjFnwpLSWlfnVNnWl",
		"nZBRbBJzznNNCnJZwnBSCJMcpcTpcwhcqhmsmWMwFWLL",
		"jQfvjgtfvPlHHqWpvWThpWqWch",
		"VljjjgjQjrTDlDgrHtVCbnJZzNzNbnRNNJZrJR",
		"MQtJnttlMLlJQsNhQrVVrFVWRRbbVFdJDD",
		"vGjvzmjzgHqSjjSzmSGHTWbfDFWrbFzFfdDVrfRWDb",
		"qPRqvTSPggqGgHCmllnCNLtnhcnnsnnw",
		"zrlZsQMFrsgQFMMjMCbjVDCTCW",
		"NqHNRdBppcJJcTpdmRfHThpdDWDtvbWVtbLjWbttWqqCCbLt",
		"mhJpJHTJmBhcJhwhgwzsQwSSlzQQzGlZ",
		"TvsszlvnzRRVTqzVrqrjjZGPfQPFqPqG",
		"mcNhDNchppWmWSNhdSmSCQNjPFjrfGjrgPFCrgFPgPgrLf",
		"SDddWpdMWSwNDmMNwlJRQwJlsVRRvzlsHt",
		"DTtggjsFFFTlPJhvctBqBqSRmSMBSRnmnRcm",
		"fGfwZdrbHVLdbGdHHwwQGVwBBCMMfvCNRNSMMMSRBmmRCN",
		"dGZzGHGVVbvHvHwbzpGbHLrwFDDFTtsglhFspgJshslTDJjT",
		"CbzspssWwCPcvvplrfqfDCJrDqdllB",
		"LjttnjNTNGgQQJdBrffTwB",
		"nVtLSgggjFwtMczhvzpZbSZW",
		"HCzCHHvWthWFHhssWCVmnqZrnqVrmrmgnbrqmN",
		"wPPGBjQQGwGbSlSLwgnpnrBZnBBmnMNnMN",
		"jTTbJlJjPPLPGHHTthhhHcFWTT",
		"qRdvvPDrCpzPHzcdrrcRqtbJJgjhgtWjJgbWJtgCFb",
		"GTwGwNscLllGTZmGSTZGlSBMnhggjbgtgbtbsgWFFMhbMF",
		"ZSQBSmlmzcrdQRqz",
		"cSpTRphwwghRfgSScqPpnDqDCjDjJJJJDvDLCvvn",
		"BVmmQFQBQVNBVmsWlbQFGBBlCHTJznzHLHvvCnjjNLHJDLHD",
		"MFsZZMbBGblbQTmQsFsQMMfPcPcwSpwtStgPphZtctPc",
		"QZbbZBdjPBjbQQbZnSSltlfwWvlvwNtNjwFMMN",
		"DLVqTJqpSVtfsptwfWpv",
		"rcRRVVTSbPQBPrBZ",
		"tjSgSjLFSnVjDWRsQj",
		"lcdqhfFpqZGpZqznrVRWPrnWRVBsVG",
		"FHddNNNHwTHMHvvS",
		"qCSDSQlwBHNbgJrHnLJH",
		"GRpRpRfnmRWWVWgVrF",
		"jhdZjpnvGfTZZQPlCtqQQSsS",
		"FMZSGWWBrZjMBZMrBWMGjjZDnCRqpgPnbRwPbFnvvqFnDR",
		"QHcpfVVslfdVlQclcctqRgqgbsCwbCwPCCCPwD",
		"NLHfLhclmmhdfNNpfQMBmZWBrJMmZWBzMrjj",
		"pBMpRgBMQwzRthmzLC",
		"HPcJvrvDbjvrFDcvWrHfHfWHmdddtdTLztmtdtfllmNdNhNz",
		"DvPFDvnPJLngQsggMGGQ",
		"BbcFHvbhhDbbTSvZmwwgJPPlDlZldd",
		"prCrNLMNgWWJBdrJ",
		"fQMLCfLLtpqsNNMnnfBhcBSVGbhhhcqVbcjc",
		"ZchcZZjmmNpgmJtgmM",
		"RLrHllWrQZQGlBpbGFGFFM",
		"RQnLHrqPLnZHzqjfVPcvVTfCvPTC",
		"fMtwjfMwrbjfGrtrpPGrwpNNVNVqcbdVqHZTFNbcHSNL",
		"mgzvDnJmnJhFJHSTNqZLHncHLS",
		"vRzhzslJFhRffPPQMjGtGl",
		"VMMNjWppQVwzNWrZdrrtMCMZCtMT",
		"ngDScLcvPPgDPDGhGDPGSHVbHTHmZtTSrBHZbZBmBb",
		"LhlglLghnVlplswJjs",
		"bGJQZZTQQLJJbQZlTZLjCGQTsDhWFhmshhvjWVFVVrgtDsst",
		"NScqwHcwwnnzBwqPqqsmVNhgsDDVtsghrFFg",
		"pcrcwnpcffrcBzfbCRLpRLMMRlRLQl",
		"hzCzCzpRgCzzzCctNsNWNqsZqZhPqNPb",
		"TdBwmdrrrDmvwTvqNsSRssPlsWsq",
		"FDBRRHDMTmBfmrmngnpjGgVptMgLCp",
		"ZPLLnSPMFGvFZMSvHhDhqHfqvfqbDW",
		"GgcppCgBcrQBBgplrVddhDqqqfdHgWdfqb",
		"CcCjQszmGBQjrcCwCmCccPwPTPnMPTnMJSMMRZSPJL",
		"LcVVcqqSHRLzRnCfNnGzNW",
		"LZPPdljlCggMjgNM",
		"PTvwlPtwtlJvZTQvbcHppFLHVVTcFssF",
		"fpWzvzNgWJBVfBJzWzBVJNzWbZcbHhlbthjlrrPrjZZPHZhJ",
		"hRDmGCFDwQnStncrjnccHcMP",
		"GmmsGRmFTsFwSCsRQDsCSqqpfvfgzddWggvqdpfBWzVh",
		"wjRBFljJGDFwwlGGpBSjGDtwTVtTgHHHsHHsVTVzsHqq",
		"CPLNPdbWvbMWbcmvPNdLVqtsHqgCqHChZhhsVsHt",
		"PWcPfPvmvNQbbWdWpJjJBDptGnDFjftn",
		"mFFmJpDMmmnJFjWDVclsSpcflSsQwSsc",
		"HrjNNjHNfVwLNSSl",
		"tdZbhjHZHPbdCTvbbhhrGbbHMFmRMvnRRFmmvJMDmgJDJMnq",
		"szJZhshbsfZJjbttchPctdTnWnRWVWMMnBdLRpMnBz",
		"SrNwvDSwrCmnVRvjpWLBBn",
		"ggGmgNFrgSDwmNgrCmtPsZPsjQGsqPcsqqJP",
		"gjSWSjJSWrWzppzW",
		"MCMzHNGNqHfscsFtrtwscVcr",
		"qGHNGNHLCnLmTCHfMMmNTzzldzgJlJZZgJljgTdD",
		"QGTQtQzTmdTsGTLcdFTGzdtBBjtwvBBJDvDMHJgjJvww",
		"lPlqsZWnDJjZvZgV",
		"ShCfCRnWGFsRRRrF",
		"lwGtndCrrmGCwdmhzQrBzrHvLVggPgHv",
		"fjMjDZJqSDJfJqDNDjJffjZLHPHHFvVFzHBLgLFpFpBSgL",
		"MsTZWRNZfJZZqMGVGhhlhhccRnhC",
		"MMvncqvcHcSnsdzzgvdfQjpljpQVTdDQDRTRlVpQ",
		"wLCrNtBFFHHThRlH",
		"bPJtHmCWssqgGPvq",
		"LvTLsmDWvTWqTsmqjRTmjwgdwgnMHMMFgdtHmBmFVn",
		"rlSCJzCSfpGGlhznQdnwFhtHgBFwtV",
		"SGZJJSSrVfCbGJLjPsWbvjRsPTqR",
		"pNqVVDCMVMBpqJVdMNHrccGHrtNtTFFFrQ",
		"hwmllWbvvbnPvbSvtrFhhJzzHztcTztT",
		"WSnbnPbbbvlWlRvnsqqMgLRMjLgVLCJdRV",
		"GphVTGVMtQwtJmtCJP",
		"FRRsBBsFqRNZNNrgqBdRfCZvbmPgmQzJQPnmJbJmQPJPPmwj",
		"RNqsFrRfZZsZWvNqWRFvrBZvWhhCGVplhlWTlTpSCLpMhWMD",
		"RZRjgbZHjjhsSnRsZstDRStsTVpFhBqFphMqPPpTFQVMPFTM",
		"zrcGJwNNdwJrfNdJWvGdJzdTlTFlqTVPFTVFPPBpqNTbBP",
		"WwLdLGfrRLStCZbD",
		"mrmTqJWTvDDppTDb",
		"DGzBfCzNDzdMwnLlbn",
		"FVZPFZFFZPgjmWZsDtsq",
		"TpnFTnFRCgRgldMRnDnRcrcdbdPBHbtPqbVcccrH",
		"WNWLfQQmfhhSNwmrcbSVqPtbZDZcPb",
		"LQhwLQvQvNfJhJRDMGFRlCMDMD",
		"vLFTDmjVvLgnNHPphN",
		"lMClGCmsRdCnPzCccngCpz",
		"dlGZwRsRrRwswGsdSbbZSbVDrVBmDWWWFJrTrFvFTmqV",
		"SGsZRqGLWLLtZRHRRcLHGTlJjzgJpjzTpNTNJNWpTm",
		"MPMPvFFvFBrPPDPMQMPChjgpNpSNTmmmpNlTDljlTz",
		"vnhrvMvnhSRqqLqnfn",
		"mGFrlBmFQNQFljhqqqqbmHMsTPRbWWCsLMWRsb",
		"wnwtvpwVzDVpvzzwZppnctMLtMPWWCstTsWTsTLffRRW",
		"vwDJgZnvZJFqgLBFGqgl",
		"QdGltnWNWqTdqQWvWsMJcrTcFcrgshJRMs",
		"BzPLCDPzzzzCCLLfCBzfSDmLMrDJMglrcRbbhRsFhMrRJcsM",
		"fjSzwwHfSzPzfCVBHlpdjGnZqnZptqQWjGvG",
		"VbJZbgVzvzmhQpQWpQzhDp",
		"tHPPcGcFBlCctCGtGcBBNlDLMGfMLwWfwwqMLLJwQWwp",
		"dCHTPTPJdTBFPdrZjgsjrjnmdgms",
		"JJpBvJQBZVvcFqqnsWdWvjsn",
		"DCfbDbTtbgfCSHqqNdFMPhPDFnPPDWsPjM",
		"bTmzTNCTNmfqTgJQcpLrpZLzVlVL",
		"dtTLntTjzTftnmwnqGGQHNmm",
		"SWbShCPMBgBRRFSFtRZZmm",
		"DlJPCJCgPWhttzpvdjcpVl",
		"WdzsNvWMzNsMHWddWCVffqmSmScLPvLPgLgLPplrrPmL",
		"BtnzbnBhbwttwtZlmmlgcwSrLgmmpm",
		"bFhQtbGBTnjBBbjTtFBbVDzddDDfjdDDqNWVjWHj",
		"ppmtpgLLZLCbMQvQQThdtrvPhV",
		"BBlHBwHRjHqBzzbHHqjjQdDQTDhPQDvnQlrQDQvr",
		"HGjFzwHNczbzRFcGzHGFSJSpspsmpssMLLSZCppmfs",
		"MpGrMMMcTsHMVHcvbwwmmcRSmDmDmv",
		"zCNptqCBQQLCNLCzbfvSvbSzSDRDSmSv",
		"CNNqNgNQJNgQtCqLlllZdZhTrThsnHpVVssPTsGP",
		"jhSGcShDrLcLLFcw",
		"MVzQvQNZVLHvHPdhLW",
		"qzhhQlVbgqjmSjJDsgmR",
		"CFzSPCgcsVVzFgzSCsBJwjdwJtNllnwglJlp",
		"QrvbqWvvLbmvDMMmbdwFWpNNwwwwptjJWn",
		"RZRZZqvvvDbDHCRTGchHFSGG",
		"SszgPSPPVltDlqtz",
		"WfTdTBdQdFnWBBBhBhNjVJtpNsVlDDDHHJWp",
		"hQhrLFsBwdQPggbRgPwRMg",
		"frRppMMDMpDnJfprnZhrrhpzWgvvGCvvFzWFvzvVVWFGJB",
		"TcmLwTsccqwqbPwsdwqdTPSvBvzzztvggVvQCGWQCLBvCv",
		"sswNjscwmqjwSssjdZNMfHHlHhfrnrgnfR",
		"JpBJBdmdzZzzpngmbCnlqnNbNM",
		"MMTHGccLTLvwRMlRnnQnbblnRnSs",
		"vVGtvMcjLVGHfHDrPPWZppBpJpfZZZ",
		"FGJtlttPdPtGFldlPRGpJTVzSBSSggHgJjVmBMHjJm",
		"rhbvqrQLrWqrWLLfqbjjgNmVNSgzTmNgNS",
		"hsffZQqnqCfZzlPPGlRlcwDs",
		"HDDdZpcFwHFRFcZqDctpRDHpwTCVwjrBTQTBLBLBJJBjjQTJ",
		"ldlMzhlPshPbLrrVrQQCMQjB",
		"glzNfWlvbHqSdNNNcF",
		"jZCMtnZZHCZwBWMwCwtMmfPFfvHDvzHFLPmFDfvh",
		"RcrQdRRdGTzGvDGmfgjh",
		"TsQscdQsQNTNqQQpRrRVCCBMMJJWMMVNVjnNJM",
		"zVPWhVzLzWBWHZnlqBllqlpRbGNdffscGNdbDRnNSfcG",
		"MtvSFQQwMcpsGRNGFR",
		"vvTwJJSgmCSMmjVPPJWWhzllWLVV",
		"RjdfnJfmbVvVJVFQcs",
		"rZDZGBBZVvLZLHFW",
		"qPzTDPlVrjNgfCdmPd",
		"bcjmQPrnbmVmsLVrLrjmcHGRWlZHHRwHpZRHWWwH",
		"nFhqzFqJzDJfvfSFqFfGHWZZHGRJRWHZWdpWwZ",
		"hBCtDSSFCTqCCFzSnzMrLNmrMNPTNMQPMmNL",
		"qvNBSJVDJGGVSJbVDDVhDbbqPjpWpWzWrnpWvvWPMjnWnpWz",
		"mlTltwcwMWTPfNTN",
		"CtCwFmCgmcmlRFmFCtRCHgmDJsbBhVqsbBHVDbNHDHJqqb",
		"csBFBsLrBGBWcgLcBvRgpRhbwRwlbQwbwQgD",
		"DCqmDmtTRtRlhdlh",
		"qnCmTNPmmCnSSzmzNzGLzLccGDBzGrBLvvcW",
		"FjfBjHnHzPFwhvFFqh",
		"bjRpGsNsPqQvPclb",
		"NWGGWGrrZVZjsCLmDMMgzgrSnzSm",
		"MDgmmsNCmZMWmHCZLrvnLBBjPLVlPVbW",
		"zcJGQwJdFRnrBVzqzvPr",
		"hTQwhJwcfTFddFdGSfcRQQGFsggsgsHHnSmgsgsmgCnHNZpC",
		"BPfwzfsgsvfszvBRbQpttRVpJbJpVg",
		"LhTmHLbmbcFTFrWCbFqhFHLHVRpVtQpZVVDVprnDMJtJQnVZ",
		"TGWWbTFFGTqlHhqhSdNdNfNSldjjBfjv",
		"zCzpWTccHlWcPzMljMttbJfjmlfm",
		"DqqQVZZqVsqJnbbnmjbJJQ",
		"ZRmDZsSgVmGLsVqsLDFvrcccHrcTWCgWHBCHcCWp",
		"cvGlQMtQlPtQWWMlcGsrFwFdbgdbdGGDCDCwdd",
		"VChVZNBVjTTfhNTFgzrzrJgSdzgzwf",
		"THThZTqZRHZRqNVZNTVLjRCMmQsntQctMnsPmMmMcWtLMQ",
		"pNRHrbNlNnRLNpMMMTrcGcGTcccz",
		"ZttBmsJmZdjsvTTvvdBMjDhfMGWGDfDfcScjfD",
		"CmtTtwvtCsgllNHPPFbLpC",
		"NpQcvwwRHvdfRvQsNfBQNvfRhVmVMqsZMmMshjMMtWZtMmrm",
		"CGHbSSzFLSSHzTnbLnCWMrtWMtjnZMhZrqZtqW",
		"FzCPPzLbPgFJbHSPldNRpgNfvvccgvwf",
		"nSjpnnhNchMQZMSScnshshncJCGwHGClwmHPZlJPTVZCwHJf",
		"LvtzBTgLWgLPlPwHPLPJ",
		"dTBDqRqFzzhQFhshhNhM",
		"HjjdPsjnllHsbnnDnbTBzLBFBZLLpRFRcCHRFz",
		"wqqWwQhQQMCQffqqhtwMGhpZFRRZvzWzFvBvpvmcRvZm",
		"fGfghtNhthqJrQqMqMMSgDdbPjbssDbdSnjCdd",
		"cqPwJJnnffBFqSfJFnDDPVplLdglGgLVjzGLdVSzVt",
		"WHRTWNHsQTNbzsbCbTsvWrWtjlgVdLgLdvdgvmLjpGlgtm",
		"ZMQrTbNHZNsHHrQCZrNDFzhwnMJcfnDhJPPPFh",
		"LRCFbjNjbCZDmtmqmRRmLtFJBgWBBpvJMwBJvGjBBvMBgw",
		"TTrlfHzccVllZhdQgdGMJWvgWgBndwpG",
		"fVSshSVlsfslhsSHHSZtZZNmNFmtmbFCDF",
		"SPGCBPDMtbcbCtchSMccDTTrrrTFTrsrMTWHTHFVWF",
		"JmnzqVmmwwfpJpmdHRTRsdsTrFdrQp",
		"LqwLgzJgnjqLwgGcVbtjDGjcVbhv",
		"PQcMvrvMsvmdSPPVccmSJcSpGBWWWbBHfWWnfttJWnWJpJ",
		"wDzqhjzmqRzDRwqDzNDbWtjWBBBtGbtHpHnnBf",
		"zglRhDqqDZgRNmZQVCdcCPQvvdZv",
		"RpVjRgvFjGBNWtBWFDtt",
		"dcqQwlqMMsCLLfbgQmtD",
		"snlgzsggTzSTSJTr",
		"dLHhDdtlMngFcFsFLFzzsj",
		"vWRGGRVrrWvvGQQJBRsmQzmsqnffqcNfNcfz",
		"vSRVJBVBwTvWTnHphTgDgtMpDl",
		"bvvGnnJbfPmfdgJJSVtwwCpTScVfNpSC",
		"sjsZWDqBqqMRZsDjbWMVwtwNNcNtScRHpRRttp",
		"hzhDqqWDzZzDZzZLQPJPdPnPvlrbGdlnFQ",
		"PwWHTwzFvNHsNzmmMwzNWGQrCqCFjpZbpnGqrqnpbr",
		"gRVRgJRJlDLSJddDccQVrtZnCqjndnrZdnqnqpdq",
		"chhgSSJfQhRRcSSSSBLVfzmzHTNzMNsTNWHMMvMP",
		"lftqSpBSvhlDBDlhBSczQGmcFMcMVVFMmGFWsm",
		"rHLHTNdggsLLnwLHbTTgdrTMPPmMGWZGQQMzQVQFZQGM",
		"gbJnrHHjnbrgLrRrHpBJvSBDDsfJsDtstq",
		"dBTtFLTtVmpdLhMprSRSWMRSMR",
		"QvJvQbjbCgCQRBhzzRsNWNBC",
		"bjgGqQGbQnjGQgnQgbGgjJnDLHLdfPVtdDmLZdBFVVZttdTf"
	};
	bool	quit;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	size_t	sum;

	printf(	"---------------------------\n"
			"Advent of Code 2022: Day 3 Part Two!\n"
			"---------------------------\n");
	i = 0;
	sum = 0;
	while (i < INPUT_SIZE)
	{
		quit = false;
		j = 0;
		// printf("-\t\t\t%s\n", input[i]);
		while (!quit && input[i][j] != '\0')
		{
			k = 0;
			while (!quit && input[i + 1][k] != '\0')
			{
				if (input[i][j] == input[i + 1][k])
				{
					l = 0;
					while (!quit && input[i + 2][l] != '\0')
					{
						if (input[i][j] == input[i + 2][l])
						{
							quit = true;
							sum += get_priority(input[i][j]);
						}
						l++;
					}
				}
				k++;
			}
			j++;
		}
		i += 3;
	}
	printf("The sum is %I64i\n", sum);
	return (0);
}