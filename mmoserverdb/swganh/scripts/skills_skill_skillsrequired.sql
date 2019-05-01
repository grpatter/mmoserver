/*
---------------------------------------------------------------------------------------
This source file is part of SWG:ANH (Star Wars Galaxies - A New Hope - Server Emulator)

For more information, visit http://www.swganh.com

Copyright (c) 2006 - 2010 The SWG:ANH Team
---------------------------------------------------------------------------------------
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
---------------------------------------------------------------------------------------
*/

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

use swganh;

--
-- Definition of table `skills_skill_skillsrequired`
--

DROP TABLE IF EXISTS `skills_skill_skillsrequired`;
CREATE TABLE `skills_skill_skillsrequired` (
  `skill_id` int(10) unsigned NOT NULL,
  `required_skill` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`skill_id`,`required_skill`),
  KEY `fk_skillsrequired_req_skill` (`required_skill`),
  CONSTRAINT `skills_skill_skillsrequired_ibfk_1` FOREIGN KEY (`required_skill`) REFERENCES `skills` (`skill_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `skills_skill_skillsrequired_ibfk_2` FOREIGN KEY (`skill_id`) REFERENCES `skills` (`skill_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `skills_skill_skillsrequired`
--

/*!40000 ALTER TABLE `skills_skill_skillsrequired` DISABLE KEYS */;
INSERT INTO `skills_skill_skillsrequired` (`skill_id`,`required_skill`) VALUES
 (13,11),
 (17,11),
 (21,11),
 (25,11),
 (14,13),
 (15,14),
 (16,15),
 (12,16),
 (585,16),
 (18,17),
 (19,18),
 (20,19),
 (12,20),
 (281,20),
 (22,21),
 (23,22),
 (24,23),
 (12,24),
 (262,24),
 (26,25),
 (27,26),
 (28,27),
 (12,28),
 (262,28),
 (281,28),
 (33,31),
 (37,31),
 (41,31),
 (45,31),
 (319,32),
 (34,33),
 (35,34),
 (36,35),
 (32,36),
 (338,36),
 (528,36),
 (604,36),
 (38,37),
 (39,38),
 (40,39),
 (32,40),
 (42,41),
 (43,42),
 (44,43),
 (32,44),
 (338,44),
 (357,44),
 (46,45),
 (47,46),
 (48,47),
 (32,48),
 (604,48),
 (53,51),
 (57,51),
 (61,51),
 (65,51),
 (300,52),
 (566,52),
 (54,53),
 (55,54),
 (56,55),
 (52,56),
 (58,57),
 (59,58),
 (60,59),
 (52,60),
 (62,61),
 (63,62),
 (64,63),
 (52,64),
 (66,65),
 (67,66),
 (68,67),
 (52,68),
 (357,68),
 (73,71),
 (77,71),
 (81,71),
 (85,71),
 (74,73),
 (75,74),
 (76,75),
 (72,76),
 (376,76),
 (395,76),
 (452,76),
 (471,76),
 (992,76),
 (78,77),
 (79,78),
 (80,79),
 (72,80),
 (414,80),
 (433,80),
 (82,81),
 (83,82),
 (84,83),
 (72,84),
 (490,84),
 (86,85),
 (87,86),
 (88,87),
 (72,88),
 (93,91),
 (97,91),
 (101,91),
 (105,91),
 (94,93),
 (95,94),
 (96,95),
 (92,96),
 (186,96),
 (509,96),
 (547,96),
 (98,97),
 (99,98),
 (100,99),
 (92,100),
 (205,100),
 (102,101),
 (103,102),
 (104,103),
 (92,104),
 (224,104),
 (106,105),
 (107,106),
 (108,107),
 (92,108),
 (243,108),
 (112,110),
 (116,110),
 (120,110),
 (124,110),
 (528,111),
 (547,111),
 (113,112),
 (114,113),
 (115,114),
 (111,115),
 (129,115),
 (117,116),
 (118,117),
 (119,118),
 (111,119),
 (148,119),
 (509,119),
 (121,120),
 (122,121),
 (123,122),
 (111,123),
 (167,123),
 (125,124),
 (126,125),
 (127,126),
 (111,127),
 (566,127),
 (604,127),
 (131,129),
 (135,129),
 (139,129),
 (143,129),
 (132,131),
 (133,132),
 (134,133),
 (130,134),
 (136,135),
 (137,136),
 (138,137),
 (130,138),
 (140,139),
 (141,140),
 (142,141),
 (130,142),
 (144,143),
 (145,144),
 (146,145),
 (130,146),
 (150,148),
 (154,148),
 (158,148),
 (162,148),
 (151,150),
 (152,151),
 (153,152),
 (149,153),
 (155,154),
 (156,155),
 (157,156),
 (149,157),
 (159,158),
 (160,159),
 (161,160),
 (149,161),
 (163,162),
 (164,163),
 (165,164),
 (149,165),
 (169,167),
 (173,167),
 (177,167),
 (181,167),
 (170,169),
 (171,170),
 (172,171),
 (168,172),
 (174,173),
 (175,174),
 (176,175),
 (168,176),
 (178,177),
 (179,178),
 (180,179),
 (168,180),
 (182,181),
 (183,182),
 (184,183),
 (168,184),
 (188,186),
 (192,186),
 (196,186),
 (200,186),
 (189,188),
 (190,189),
 (191,190),
 (187,191),
 (193,192),
 (194,193),
 (195,194),
 (187,195),
 (197,196),
 (198,197),
 (199,198),
 (187,199),
 (201,200),
 (202,201),
 (203,202),
 (187,203),
 (207,205),
 (211,205),
 (215,205),
 (219,205),
 (208,207),
 (209,208),
 (210,209),
 (206,210),
 (212,211),
 (213,212),
 (214,213),
 (206,214),
 (216,215),
 (217,216),
 (218,217),
 (206,218),
 (220,219),
 (221,220),
 (222,221),
 (206,222),
 (226,224),
 (230,224),
 (234,224),
 (238,224),
 (227,226),
 (228,227),
 (229,228),
 (225,229),
 (231,230),
 (232,231),
 (233,232),
 (225,233),
 (235,234),
 (236,235),
 (237,236),
 (225,237),
 (239,238),
 (240,239),
 (241,240),
 (225,241),
 (245,243),
 (249,243),
 (253,243),
 (257,243),
 (246,245),
 (247,246),
 (248,247),
 (244,248),
 (250,249),
 (251,250),
 (252,251),
 (244,252),
 (254,253),
 (255,254),
 (256,255),
 (244,256),
 (258,257),
 (259,258),
 (260,259),
 (244,260),
 (264,262),
 (268,262),
 (272,262),
 (276,262),
 (265,264),
 (266,265),
 (267,266),
 (263,267),
 (269,268),
 (270,269),
 (271,270),
 (263,271),
 (273,272),
 (274,273),
 (275,274),
 (263,275),
 (277,276),
 (278,277),
 (279,278),
 (263,279),
 (283,281),
 (287,281),
 (291,281),
 (295,281),
 (284,283),
 (285,284),
 (286,285),
 (282,286),
 (288,287),
 (289,288),
 (290,289),
 (282,290),
 (292,291),
 (293,292),
 (294,293),
 (282,294),
 (296,295),
 (297,296),
 (298,297),
 (282,298),
 (302,300),
 (306,300),
 (310,300),
 (314,300),
 (303,302),
 (304,303),
 (305,304),
 (301,305),
 (307,306),
 (308,307),
 (309,308),
 (301,309),
 (311,310),
 (312,311),
 (313,312),
 (301,313),
 (315,314),
 (316,315),
 (317,316),
 (301,317),
 (321,319),
 (325,319),
 (329,319),
 (333,319),
 (322,321),
 (323,322),
 (324,323),
 (320,324),
 (326,325),
 (327,326),
 (328,327),
 (320,328),
 (330,329),
 (331,330),
 (332,331),
 (320,332),
 (334,333),
 (335,334),
 (336,335),
 (320,336),
 (340,338),
 (344,338),
 (348,338),
 (352,338),
 (341,340),
 (342,341),
 (343,342),
 (339,343),
 (345,344),
 (346,345),
 (347,346),
 (339,347),
 (349,348),
 (350,349),
 (351,350),
 (339,351),
 (353,352),
 (354,353),
 (355,354),
 (339,355),
 (359,357),
 (363,357),
 (367,357),
 (371,357),
 (360,359),
 (361,360),
 (362,361),
 (358,362),
 (364,363),
 (365,364),
 (366,365),
 (358,366),
 (368,367),
 (369,368),
 (370,369),
 (358,370),
 (372,371),
 (373,372),
 (374,373),
 (358,374),
 (378,376),
 (382,376),
 (386,376),
 (390,376),
 (379,378),
 (380,379),
 (381,380),
 (377,381),
 (383,382),
 (384,383),
 (385,384),
 (377,385),
 (387,386),
 (388,387),
 (389,388),
 (377,389),
 (391,390),
 (392,391),
 (393,392),
 (377,393),
 (397,395),
 (401,395),
 (405,395),
 (409,395),
 (398,397),
 (399,398),
 (400,399),
 (396,400),
 (402,401),
 (403,402),
 (404,403),
 (396,404),
 (406,405),
 (407,406),
 (408,407),
 (396,408),
 (410,409),
 (411,410),
 (412,411),
 (396,412),
 (416,414),
 (420,414),
 (424,414),
 (428,414),
 (417,416),
 (418,417),
 (419,418),
 (415,419),
 (421,420),
 (422,421),
 (423,422),
 (415,423),
 (425,424),
 (426,425),
 (427,426),
 (415,427),
 (429,428),
 (430,429),
 (431,430),
 (415,431),
 (435,433),
 (439,433),
 (443,433),
 (447,433),
 (436,435),
 (437,436),
 (438,437),
 (434,438),
 (440,439),
 (441,440),
 (442,441),
 (434,442),
 (444,443),
 (445,444),
 (446,445),
 (434,446),
 (448,447),
 (449,448),
 (450,449),
 (434,450),
 (454,452),
 (458,452),
 (462,452),
 (466,452),
 (455,454),
 (456,455),
 (457,456),
 (453,457),
 (459,458),
 (460,459),
 (461,460),
 (453,461),
 (463,462),
 (464,463),
 (465,464),
 (453,465),
 (467,466),
 (468,467),
 (469,468),
 (453,469),
 (473,471),
 (477,471),
 (481,471),
 (485,471),
 (474,473),
 (475,474),
 (476,475),
 (472,476),
 (478,477),
 (479,478),
 (480,479),
 (472,480),
 (482,481),
 (483,482),
 (484,483),
 (472,484),
 (486,485),
 (487,486),
 (488,487),
 (472,488),
 (492,490),
 (496,490),
 (500,490),
 (504,490),
 (493,492),
 (494,493),
 (495,494),
 (491,495),
 (497,496),
 (498,497),
 (499,498),
 (491,499),
 (501,500),
 (502,501),
 (503,502),
 (491,503),
 (505,504),
 (506,505),
 (507,506),
 (491,507),
 (511,509),
 (515,509),
 (519,509),
 (523,509),
 (512,511),
 (513,512),
 (514,513),
 (510,514),
 (516,515),
 (517,516),
 (518,517),
 (510,518),
 (520,519),
 (521,520),
 (522,521),
 (510,522),
 (524,523),
 (525,524),
 (526,525),
 (510,526),
 (530,528),
 (534,528),
 (538,528),
 (542,528),
 (531,530),
 (532,531),
 (533,532),
 (529,533),
 (535,534),
 (536,535),
 (537,536),
 (529,537),
 (539,538),
 (540,539),
 (541,540),
 (529,541),
 (543,542),
 (544,543),
 (545,544),
 (529,545),
 (549,547),
 (553,547),
 (557,547),
 (561,547),
 (550,549),
 (551,550),
 (552,551),
 (548,552),
 (554,553),
 (555,554),
 (556,555),
 (548,556),
 (558,557),
 (559,558),
 (560,559),
 (548,560),
 (562,561),
 (563,562),
 (564,563),
 (548,564),
 (568,566),
 (572,566),
 (576,566),
 (580,566),
 (569,568),
 (570,569),
 (571,570),
 (567,571),
 (573,572),
 (574,573),
 (575,574),
 (567,575),
 (577,576),
 (578,577),
 (579,578),
 (567,579),
 (581,580),
 (582,581),
 (583,582),
 (567,583),
 (587,585),
 (591,585),
 (595,585),
 (599,585),
 (588,587),
 (589,588),
 (590,589),
 (586,590),
 (592,591),
 (593,592),
 (594,593),
 (586,594),
 (596,595),
 (597,596),
 (598,597),
 (586,598),
 (600,599),
 (601,600),
 (602,601),
 (586,602),
 (606,604),
 (610,604),
 (614,604),
 (618,604),
 (607,606),
 (608,607),
 (609,608),
 (605,609),
 (611,610),
 (612,611),
 (613,612),
 (605,613),
 (615,614),
 (616,615),
 (617,616),
 (605,617),
 (619,618),
 (620,619),
 (621,620),
 (605,621),
 (625,623),
 (629,623),
 (633,623),
 (637,623),
 (626,625),
 (627,626),
 (628,627),
 (624,628),
 (630,629),
 (631,630),
 (632,631),
 (624,632),
 (634,633),
 (635,634),
 (636,635),
 (624,636),
 (638,637),
 (639,638),
 (640,639),
 (624,640),
 (690,688),
 (698,688),
 (702,688),
 (694,689),
 (745,689),
 (691,690),
 (692,691),
 (693,692),
 (689,693),
 (695,694),
 (696,695),
 (697,696),
 (689,697),
 (699,698),
 (700,699),
 (701,700),
 (689,701),
 (703,702),
 (704,703),
 (705,704),
 (689,705),
 (709,707),
 (713,707),
 (717,707),
 (721,707),
 (726,708),
 (710,709),
 (711,710),
 (712,711),
 (708,712),
 (714,713),
 (715,714),
 (716,715),
 (708,716),
 (718,717),
 (719,718),
 (720,719),
 (708,720),
 (722,721),
 (723,722),
 (724,723),
 (708,724),
 (728,726),
 (732,726),
 (736,726),
 (740,726),
 (729,728),
 (730,729),
 (731,730),
 (727,731),
 (733,732),
 (734,733),
 (735,734),
 (727,735),
 (737,736),
 (738,737),
 (739,738),
 (727,739),
 (741,740),
 (742,741),
 (743,742),
 (727,743),
 (747,745),
 (751,745),
 (755,745),
 (759,745),
 (764,746),
 (748,747),
 (749,748),
 (750,749),
 (746,750),
 (752,751),
 (753,752),
 (754,753),
 (746,754),
 (756,755),
 (757,756),
 (758,757),
 (746,758),
 (760,759),
 (761,760),
 (762,761),
 (746,762),
 (766,764),
 (770,764),
 (774,764),
 (778,764),
 (767,766),
 (768,767),
 (769,768),
 (765,769),
 (771,770),
 (772,771),
 (773,772),
 (765,773),
 (775,774),
 (776,775),
 (777,776),
 (765,777),
 (779,778),
 (780,779),
 (781,780),
 (765,781),
 (786,784),
 (790,784),
 (794,784),
 (787,786),
 (788,787),
 (789,788),
 (785,789),
 (791,790),
 (792,791),
 (793,792),
 (785,793),
 (795,794),
 (798,794),
 (785,797),
 (796,797),
 (800,799),
 (801,800),
 (785,801),
 (805,803),
 (809,803),
 (813,803),
 (817,803),
 (806,805),
 (807,806),
 (808,807),
 (804,808),
 (810,809),
 (811,810),
 (812,811),
 (804,812),
 (814,813),
 (815,814),
 (816,815),
 (804,816),
 (818,817),
 (819,818),
 (820,819),
 (804,820),
 (824,822),
 (828,822),
 (832,822),
 (836,822),
 (825,824),
 (826,825),
 (827,826),
 (823,827),
 (829,828),
 (830,829),
 (831,830),
 (823,831),
 (833,832),
 (834,833),
 (835,834),
 (823,835),
 (837,836),
 (838,837),
 (839,838),
 (823,839),
 (843,841),
 (847,841),
 (851,841),
 (855,841),
 (844,843),
 (845,844),
 (846,845),
 (842,846),
 (848,847),
 (849,848),
 (850,849),
 (842,850),
 (852,851),
 (853,852),
 (854,853),
 (842,854),
 (856,855),
 (857,856),
 (858,857),
 (842,858),
 (863,861),
 (867,861),
 (871,861),
 (875,861),
 (864,863),
 (865,864),
 (866,865),
 (862,866),
 (868,867),
 (869,868),
 (870,869),
 (862,870),
 (872,871),
 (873,872),
 (874,873),
 (862,874),
 (876,875),
 (877,876),
 (878,877),
 (862,878),
 (882,880),
 (886,880),
 (890,880),
 (894,880),
 (883,882),
 (884,883),
 (885,884),
 (881,885),
 (887,886),
 (888,887),
 (889,888),
 (881,889),
 (891,890),
 (892,891),
 (893,892),
 (881,893),
 (895,894),
 (896,895),
 (897,896),
 (881,897),
 (901,899),
 (905,899),
 (909,899),
 (913,899),
 (902,901),
 (903,902),
 (904,903),
 (900,904),
 (906,905),
 (907,906),
 (908,907),
 (900,908),
 (910,909),
 (911,910),
 (912,911),
 (900,912),
 (914,913),
 (915,914),
 (916,915),
 (900,916),
 (920,918),
 (924,918),
 (928,918),
 (932,918),
 (921,920),
 (922,921),
 (923,922),
 (919,923),
 (925,924),
 (926,925),
 (927,926),
 (919,927),
 (929,928),
 (930,929),
 (931,930),
 (919,931),
 (933,932),
 (934,933),
 (935,934),
 (919,935),
 (939,937),
 (943,937),
 (947,937),
 (951,937),
 (940,939),
 (941,940),
 (942,941),
 (938,942),
 (944,943),
 (945,944),
 (946,945),
 (938,946),
 (948,947),
 (949,948),
 (950,949),
 (938,950),
 (952,951),
 (953,952),
 (954,953),
 (938,954),
 (959,957),
 (960,959),
 (961,960),
 (962,961),
 (963,962),
 (964,963),
 (965,964),
 (966,965),
 (967,966),
 (968,967),
 (958,968),
 (972,971),
 (973,972),
 (974,973),
 (975,974),
 (976,975),
 (977,976),
 (978,977),
 (979,978),
 (980,979),
 (981,980),
 (971,981),
 (986,984),
 (987,986),
 (861,987),
 (880,987),
 (899,987),
 (918,987),
 (937,987),
 (988,987),
 (989,988),
 (994,992),
 (998,992),
 (1002,992),
 (1006,992),
 (995,994),
 (996,995),
 (997,996),
 (993,997),
 (999,998),
 (1000,999),
 (1001,1000),
 (993,1001),
 (1003,1002),
 (1004,1003),
 (1005,1004),
 (993,1005),
 (1007,1006),
 (1008,1007),
 (1009,1008),
 (993,1009),
 (1014,1012),
 (1018,1012),
 (1022,1012),
 (1026,1012),
 (1015,1014),
 (1016,1015),
 (1017,1016),
 (1013,1017),
 (1019,1018),
 (1020,1019),
 (1021,1020),
 (1013,1021),
 (1023,1022),
 (1024,1023),
 (1025,1024),
 (1013,1025),
 (1027,1026),
 (1028,1027),
 (1029,1028),
 (1013,1029),
 (1033,1031),
 (1037,1031),
 (1041,1031),
 (1045,1031),
 (1034,1033),
 (1035,1034),
 (1036,1035),
 (1038,1037),
 (1040,1037),
 (1039,1038),
 (1032,1040),
 (1042,1041),
 (1043,1042),
 (1044,1043),
 (1032,1044),
 (1046,1045),
 (1047,1046),
 (1048,1047),
 (1032,1048),
 (1052,1050),
 (1056,1050),
 (1060,1050),
 (1064,1050),
 (1053,1052),
 (1054,1053),
 (1055,1054),
 (1051,1055),
 (1057,1056),
 (1058,1057),
 (1059,1058),
 (1051,1059),
 (1061,1060),
 (1062,1061),
 (1063,1062),
 (1051,1063),
 (1065,1064),
 (1066,1065),
 (1067,1066),
 (1051,1067),
 (1071,1070),
 (1076,1070),
 (1080,1070),
 (1084,1070),
 (1072,1071),
 (1073,1074),
 (1075,1074),
 (1074,1075),
 (1077,1076),
 (1078,1077),
 (1079,1078),
 (1075,1079),
 (1081,1080),
 (1082,1081),
 (1083,1082),
 (1075,1083),
 (1085,1084),
 (1086,1085),
 (1087,1086),
 (1075,1087);
/*!40000 ALTER TABLE `skills_skill_skillsrequired` ENABLE KEYS */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;