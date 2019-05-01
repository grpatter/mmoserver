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
-- Definition of table `planet_regions`
--

DROP TABLE IF EXISTS `planet_regions`;
CREATE TABLE `planet_regions` (
  `region_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `region_name` char(255) DEFAULT 'region_name',
  `region_file` char(255) DEFAULT 'region_file',
  `x` float NOT NULL DEFAULT '0',
  `z` float NOT NULL DEFAULT '0',
  `width` float NOT NULL DEFAULT '0',
  `height` float NOT NULL DEFAULT '0',
  `planet_id` int(10) unsigned DEFAULT NULL,
  `build` tinyint(3) DEFAULT '0' COMMENT '0 = build, 1 = no build',
  `no_build_type` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '1= cities, 2= badges, 3=POIs, 4=Other',
  PRIMARY KEY (`region_id`)
) ENGINE=InnoDB AUTO_INCREMENT=476 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `planet_regions`
--

/*!40000 ALTER TABLE `planet_regions` DISABLE KEYS */;
INSERT INTO `planet_regions` (`region_id`,`region_name`,`region_file`,`x`,`z`,`width`,`height`,`planet_id`,`build`,`no_build_type`) VALUES 
 (1,'dantooine_mining_outpost','dantooine_region_names',-618,2470,0,600,1,1,1),
 (2,'dantooine_pirate_outpost','dantooine_region_names',1595,-6369,0,600,1,1,1),
 (3,'dantooine_imperial_outpost','dantooine_region_names',-4228,-2389,0,600,1,1,1),
 (4,'coronet','corellia_region_names',-131,-4723,0,2200,0,1,1),
 (5,'tyrena','corellia_region_names',-5140,-2450,0,2500,0,1,1),
 (6,'bela_vistal','corellia_region_names',6800,-5700,0,2000,0,1,1),
 (7,'kor_vella','corellia_region_names',-3138,2815,0,3000,0,1,1),
 (8,'doaba_guerfel','corellia_region_names',3340,5534,0,2300,0,1,1),
 (9,'vreni_island','corellia_region_names',-5552,-6057,0,2000,0,1,1),
 (10,'dathomir_trade_outpost','dathomir_region_names',591,3075,0,600,2,1,1),
 (11,'dathomir_survey_outpost','dathomir_region_names',-84,-1600,0,600,2,1,1),
 (12,'endor_neutral_outpost','endor_region_names',-955,1557,0,600,3,1,1),
 (13,'endor_smuggler_outpost','endor_region_names',3209,-3499,0,600,3,1,1),
 (14,'lok_nyms_stronghold','lok_region_names',419,5216,0,2000,4,1,1),
 (15,'lok_imperial_outpost','lok_region_names',-1920,-3084,0,700,4,1,1),
 (16,'theed','naboo_region_names',-5160,4380,2500,1500,5,1,1),
 (17,'keren','naboo_region_names',1434,2771,3000,1500,5,1,1),
 (18,'moenia','naboo_region_names',4836,-4830.5,0,1500,5,1,1),
 (19,'deeja_peak','naboo_region_names',5333,-1577,0,1500,5,1,1),
 (20,'kaadara','naboo_region_names',5288,6687,0,1000,5,1,1),
 (21,'narmle','rori_region_names',-5140,-2368,0,1500,6,1,1),
 (22,'restuss','rori_region_names',5318,5680,0,1500,6,1,1),
 (23,'a_rebel_outpost','rori_region_names',3677,-6447,0,150,6,1,1),
 (24,'dearic','talus_region_names',422,-3004,0,1500,7,1,1),
 (25,'nashal','talus_region_names',4163,5220,0,1500,7,1,1),
 (26,'an_imperial_outpost','talus_region_names',-2178,2300,0,500,7,1,1),
 (27,'bestine','tatooine_region_names',-1296,-3589,0,1500,8,1,1),
 (28,'mos_espa','tatooine_region_names',-2878,2226,0,1500,8,1,1),
 (29,'mos_eisley','tatooine_region_names',3569,-4818,0,1500,8,1,1),
 (30,'mos_entha','tatooine_region_names',1470,3248,0,1500,8,1,1),
 (31,'mos_taike','tatooine_region_names',3855,2338,0,600,8,1,1),
 (32,'anchorhead','tatooine_region_names',65,-5330,0,800,8,1,1),
 (33,'wayfar','tatooine_region_names',-5157,-6549,0,800,8,1,1),
 (34,'yavin4_mining_outpost','yavin4_region_names',-312,4865,0,600,9,1,1),
 (35,'yavin4_labor_outpost','yavin4_region_names',-6925,-5707,0,600,9,1,1),
 (36,'pandath','taanab_region_names',299,3742,450,450,42,1,1),
 (37,'lake_retreat','naboo_region_name',-5488,-6,0,600,5,1,1),
 (38,'corellia_badge','corsec_base',5291,1494,100,100,0,0,0),
 (39,'corellia_badge','grand_theater',-5418,-6248,50,50,0,0,0),
 (40,'corellia_badge','crystal_fountain',6767,-5617,60,60,0,0,0),
 (41,'corellia_badge','agrilat_swamp',1084,4176,50,50,0,0,0),
 (42,'corellia_badge','rebel_hideout',-6530,5967,100,100,0,0,0),
 (43,'dantooine_badge','dantari_village',-3862,-5706,50,50,1,0,0),
 (44,'dantooine_badge','dantari_rock_village',-7156,-883,50,50,1,0,0),
 (45,'dantooine_badge','ab_rebel_base',-6836,5520,25,25,1,0,0),
 (46,'dantooine_badge','jedi_temple',4195,5203,25,25,1,0,0),
 (47,'dathomir_badge','imp_prison',-6304,753,100,100,2,0,0),
 (48,'dathomir_badge','tarpits',652,-4888,50,50,2,0,0),
 (49,'dathomir_badge','lesser_sarlacc',-2101,3165,50,50,2,0,0),
 (50,'dathomir_badge','escape_pod',-4427,586,25,25,2,0,0),
 (51,'dathomir_badge','lesser_misty_fall',3558,1554,25,25,2,0,0),
 (52,'dathomir_badge','downed_ship',5585,1903,50,50,2,0,0),
 (53,'dathomir_badge','great_misty_fall',3021,1289,25,25,2,0,0),
 (54,'endor_badge','ewok_tree_vill',4596,-2423,100,100,3,0,0),
 (55,'endor_badge','dulok_village',6051,-2477,100,100,3,0,0),
 (56,'endor_badge','ewok_lake_vill',-650,-5076,100,100,3,0,0),
 (57,'endor_badge','maruaders_stronghold',-4628,-2273,50,50,3,0,0),
 (58,'lok_badge','imp_outpost',-1814,-3086,50,50,4,0,0),
 (59,'lok_badge','mount_chaolt',3091,-4638,50,50,4,0,0),
 (60,'lok_badge','kimo_skeleton',4562,-1156,25,25,4,0,0),
 (61,'naboo_badge','theed_waterfall',-4628,4207,25,25,5,0,0),
 (62,'naboo_badge','peak_waterfall',5157,-1646,25,25,5,0,0),
 (63,'naboo_badge','amidala_beach',-5828,-93,50,50,5,0,0),
 (64,'naboo_badge','gungan_place',-2066,-5423,50,50,5,0,0),
 (65,'rori_badge','hyperdrive_fac',-1130,4544,100,100,6,0,0),
 (66,'rori_badge','imp_camp',-5633,-5661,50,50,6,0,0),
 (67,'rori_badge','reb_outpost',3664,-6501,100,100,6,0,0),
 (68,'rori_badge','spice_mine',7371,169,50,50,6,0,0),
 (69,'talus_badge','durbin',4133,962,50,50,7,0,0),
 (70,'talus_badge','imp_outpost',-2184,2405,50,50,7,0,0),
 (71,'talus_badge','imp_reb_batle',-2452,3846,25,25,7,0,0),
 (72,'talus_badge','aquq_cave',-4425,-1414,25,25,7,0,0),
 (73,'tatooine_badge','lars_home',-2579,-5500,25,25,8,0,0),
 (74,'tatooine_badge','bens_hut',-4512,-2270,25,25,8,0,0),
 (75,'tatooine_badge','sarlacc',-6176,-3372,25,25,8,0,0),
 (76,'tatooine_badge','escape_pod',-3930,-4425,25,25,8,0,0),
 (77,'tatooine_badge','krayt_skull',-4650,-4363,25,25,8,0,0),
 (78,'tatooine_badge','krayt_graveyard',7428,4563,50,50,8,0,0),
 (79,'tatooine_badge','fort_tusken',-3969,6267,50,50,8,0,0),
 (80,'yavin_badge','exar_kun',5076,5537,25,25,9,0,0),
 (81,'yavin_badge','blueleaf_temple',-875,-2047,50,50,9,0,0),
 (82,'yavin_badge','woolamander_palace',519,-646,25,25,9,0,0),
 (84,'a_imperial_outpost','dathomir_region_name',-6090,1010,0,600,2,1,1),
 (85,'taanab_badge','taanab_starport',299,3742,25,25,42,0,0),
 (86,'region_name','tatooine_complete',-8192,-8192,16384,16384,8,0,0),
 (87,'region_name','corellia_complete',-8192,-8192,16384,16384,0,0,0),
 (88,'region_name','dantooine_complete',-8192,-8192,16384,16384,1,0,0),
 (89,'region_name','dathomir_complete',-8192,-8192,16384,16384,2,0,0),
 (90,'region_name','endor_complete',-8192,-8192,16384,16384,3,0,0),
 (91,'region_name','lok_complete',-8192,-8192,16384,16384,4,0,0),
 (92,'region_name','naboo_complete',-8192,-8192,16384,16384,5,0,0),
 (93,'region_name','rori_complete',-8192,-8192,16384,16384,6,0,0),
 (94,'region_name','talus_complete',-8192,-8192,16384,16384,7,0,0),
 (95,'region_name','yavin_complete',-8192,-8192,16384,16384,8,0,0),
 (96,'region_name','taanab_complete',-8192,-8192,16384,16384,42,0,0),
 (97,'region_name','region_internal',-4601,4833,25,25,0,0,0),
 (98,'hideout','no_build_region',-6584,5915,0,100,0,1,3),
 (99,'corsecbase','no_build_region',5291,1494,0,100,0,1,3),
 (100,'grandtheater','no_build_region',-5421,-6212,0,100,0,1,3),
 (101,'crystalfountain','no_build_region',6760,-5617,0,100,0,1,3),
 (102,'agrilat','no_build_region',1402,3802,0,100,0,1,3),
 (103,'drall','no_build_region',1042,4193,0,100,0,1,3),
 (104,'nyax','no_build_region',1414,-317,0,100,0,1,3),
 (105,'stronghold','no_build_region',4651,-5617,0,100,0,1,3),
 (106,'afarathu','no_build_region',-2483,2907,0,100,0,1,3),
 (107,'dantari1','no_build_region',-3929,-5632,100,100,1,1,3),
 (108,'dantari2','no_build_region',-7144,-1053,100,100,1,1,3),
 (109,'dantari3','no_build_region',5655,-589,100,100,1,1,3),
 (110,'abandoned','no_build_region',-6858,5725,100,100,1,1,3),
 (111,'jeditemple','no_build_region',4258,5374,100,100,1,1,3),
 (112,'cystalhunter','no_build_region',-6259,7336,100,100,1,1,3),
 (113,'janta','no_build_region',6994,-4110,100,100,1,1,3),
 (114,'mokk','no_build_region',-7258,-3320,100,100,1,1,3),
 (115,'kunga','no_build_region',-368,-240,100,100,1,1,3),
 (116,'warren','no_build_region',-580,-3763,100,100,1,1,3),
 (117,'prison','no_build_region',-6091,1010,100,100,2,1,3),
 (118,'lessersarlacc','no_build_region',-2091,3177,100,100,2,1,3),
 (119,'dathpod','no_build_region',-4446,596,100,100,2,1,3),
 (120,'mistyfalls','no_build_region',3566,1560,100,100,2,1,3),
 (121,'tarpit','no_build_region',651,-4888,100,100,2,1,3),
 (122,'nightsister','no_build_region',-3946,-50,100,100,2,1,3),
 (123,'singing','no_build_region',678,4079,100,100,2,1,3),
 (124,'nightvssing','no_build_region',-2450,1521,100,100,2,1,3),
 (125,'nightspider','no_build_region',-1219,6262,100,100,2,1,3),
 (126,'slavecamp','no_build_region',2428,-1701,100,100,2,1,3),
 (127,'tree1','no_build_region',6,-5,100,100,3,1,3),
 (128,'tree2','no_build_region',4661,-2425,100,100,3,1,3),
 (129,'lake1','no_build_region',1578,-3271,100,100,3,1,3),
 (130,'lake2','no_build_region',-605,-4940,100,100,3,1,3),
 (131,'dulok1','no_build_region',5921,-2514,100,100,3,1,3),
 (132,'dulok2','no_build_region',-1287,2904,100,100,3,1,3),
 (133,'marauder','no_build_region',-4838,-2339,100,100,3,1,3),
 (134,'korga','no_build_region',2286,3459,100,100,3,1,3),
 (135,'orphan','no_build_region',-6853,679,100,100,3,1,3),
 (136,'jinda','no_build_region',-1695,-56,100,100,3,1,3),
 (137,'volcano','no_build_region',3091,-4638,100,100,4,1,3),
 (138,'lokimpoutpost','no_build_region',-1785,-3087,100,100,4,1,3),
 (139,'kimogilaskel','no_build_region',4572,-1114,100,100,4,1,3),
 (140,'kimogilatown','no_build_region',-68,2650,100,100,4,1,3),
 (141,'canyoncosair','no_build_region',-3792,-3904,100,100,4,1,3),
 (142,'bloodrazor','no_build_region',3703,2274,100,100,4,1,3),
 (143,'droidcave','no_build_region',3364,-4923,100,100,4,1,3),
 (144,'greatmaze','no_build_region',3824,-465,100,100,4,1,3),
 (145,'gungan','no_build_region',-2104,-5408,100,100,5,1,3),
 (146,'theedfalls','no_build_region',-4627,4207,100,100,5,1,3),
 (147,'deejafalls','no_build_region',5174,-1550,100,100,5,1,3),
 (148,'amidalasbeach','no_build_region',-5828,-93,100,100,5,1,3),
 (149,'impvsgun','no_build_region',4825,-3820,100,100,5,1,3),
 (150,'mordran','no_build_region',-1952,-5279,100,100,5,1,3),
 (151,'weaponfacility','no_build_region',-6456,-3235,100,100,5,1,3),
 (152,'narglatch','no_build_region',5864,-4681,100,100,5,1,3),
 (153,'mauler','no_build_region',2963,1109,100,100,5,1,3),
 (154,'reboutpost','no_build_region',3669,-6586,100,100,6,1,3),
 (155,'kobala','no_build_region',7304,63,100,100,6,1,3),
 (156,'impencampment','no_build_region',-5651,-5660,100,100,6,1,3),
 (157,'hyperdrive','no_build_region',-1070,4542,100,100,6,1,3),
 (158,'garyn','no_build_region',-6004,-1851,100,100,6,1,3),
 (159,'borglebat','no_build_region',902,-4933,100,100,6,1,3),
 (160,'cobral','no_build_region',5464,5045,100,100,6,1,3),
 (161,'tortoncave','no_build_region',-1814,-4533,100,100,6,1,3),
 (162,'poacher','no_build_region',773,-2109,100,100,6,1,3),
 (163,'barkmite','no_build_region',3584,5419,100,100,6,1,3),
 (164,'swamptown','no_build_region',-1986,3339,100,100,6,1,3),
 (165,'impoutpost','no_build_region',-2193,2494,100,100,7,1,3),
 (166,'creaturevillage','no_build_region',4174,1162,100,100,7,1,3),
 (167,'impvsreb','no_build_region',-2595,3724,100,100,7,1,3),
 (168,'aqualishcave','no_build_region',-4268,-1432,100,100,7,1,3),
 (169,'weapondepot','no_build_region',-4899,-3137,100,100,7,1,3),
 (170,'detainment','no_build_region',4963,-5977,100,100,7,1,3),
 (171,'corvsflail','no_build_region',2938,6004,100,100,7,1,3),
 (172,'flynock','no_build_region',1508,-858,100,100,7,1,3),
 (173,'erransif','no_build_region',2145,-5576,100,100,7,1,3),
 (174,'aakuan','no_build_region',5939,4562,100,100,7,1,3),
 (175,'khamurrabio','no_build_region',-4816,-4752,100,100,7,1,3),
 (176,'decaymite','no_build_region',-5505,-4680,100,100,7,1,3),
 (177,'binyare','no_build_region',5526,-4073,100,100,7,1,3),
 (178,'jabbaspalace','no_build_region',-5856,-6183,0,300,8,1,3),
 (179,'forttusken','no_build_region',-3980,6311,0,400,8,1,3),
 (180,'jawatraders','no_build_region',-6141,1854,0,300,8,1,3),
 (181,'darklighter','no_build_region',-718,-6683,0,400,8,1,3),
 (182,'kraytgraveyard','no_build_region',6839,4320,0,1500,8,1,3),
 (183,'larshomestead','no_build_region',-2579,-5500,100,100,8,1,3),
 (184,'kenobishouse','no_build_region',-4512,-2270,100,100,8,1,3),
 (185,'sarlacc','no_build_region',-6169,-3387,100,100,8,1,3),
 (186,'pod','no_build_region',-3931,-4397,100,100,8,1,3),
 (187,'skeleton','no_build_region',-4632,-4346,100,100,8,1,3),
 (188,'woolamander','no_build_region',467,-693,100,100,9,1,3),
 (189,'blueleaf','no_build_region',-976,-2039,100,100,9,1,3),
 (190,'exarkun','no_build_region',5163,5539,100,100,9,1,3),
 (191,'massassi','no_build_region',-3226,-3139,100,100,9,1,3),
 (192,'racingagrilat','no_build_region',1859,4642,0,100,0,1,3),
 (193,'racingkeren','no_build_region',1396,2686,100,100,5,1,3),
 (194,'racingmosespa','no_build_region',2380,5000,100,100,8,1,3),
 (199,'a_restricted_area','dathomir_region_name',-6358,930,0,600,2,1,1),
 (200,'kraytgraveyard2','no_build_region',7462,4480,0,1500,8,1,3),
 (201,'TuskenVsJawaBattle','no_build_region',5767,3998,0,300,8,1,4),
 (202,'HouseFoundation','no_build_region',2321,3252,0,60,8,1,4),
 (203,'CrashedPod','no_build_region',-5462,-931,0,60,0,1,4),
 (204,'stoneWalls','no_build_region',-3617,-358,0,60,0,1,4),
 (205,'smallBase','no_build_region',638,-440,0,60,0,1,4),
 (206,'baseRuins','no_build_region',1882,-227,0,60,0,1,4),
 (207,'NabooStyleWalls','no_build_region',4245,-159,0,60,0,1,4),
 (208,'imperial_fort','yavin4_region_names',4032,-6234,0,600,9,1,1),
 (209,'village','no_build_region',5297,-4130,0,1000,2,1,4),
 (210,'corellia_badge:corsec_base','no_build_region',5291,1494,50,50,0,1,2),
 (211,'corellia_badge:grand_theater','no_build_region',-5418,-6248,50,50,0,1,2),
 (212,'corellia_badge:crystal_fountain','no_build_region',6767,-5617,50,50,0,1,2),
 (213,'corellia_badge:agrilat_swamp','no_build_region',1084,4176,50,50,0,1,2),
 (214,'corellia_badge:rebel_hideout','no_build_region',-6530,5967,50,50,0,1,2),
 (215,'dantooine_badge:dantari_village','no_build_region',-3862,-5706,100,100,1,1,2),
 (216,'dantooine_badge:dantari_rock_village','no_build_region',-7156,-883,100,100,1,1,2),
 (217,'dantooine_badge:ab_rebel_base','no_build_region',-6836,5520,100,100,1,1,2),
 (218,'dantooine_badge:jedi_temple','no_build_region',4195,5203,100,100,1,1,2),
 (219,'dathomir_badge:imp_prison','no_build_region',-6304,753,100,100,2,1,2),
 (220,'dathomir_badge:tarpits','no_build_region',652,-4888,100,100,2,1,2),
 (221,'dathomir_badge:lesser_sarlacc','no_build_region',-2101,3165,100,100,2,1,2),
 (222,'dathomir_badge:escape_pod','no_build_region',-4427,586,100,100,2,1,2),
 (223,'dathomir_badge:lesser_misty_fall','no_build_region',3558,1554,100,100,2,1,2),
 (224,'dathomir_badge:downed_ship','no_build_region',5585,1903,100,100,2,1,2),
 (225,'dathomir_badge:great_misty_fall','no_build_region',3021,1289,100,100,2,1,2),
 (226,'endor_badge:ewok_tree_vill','no_build_region',4596,-2423,100,100,3,1,2),
 (227,'endor_badge:dulok_village','no_build_region',6051,-2477,100,100,3,1,2),
 (228,'endor_badge:ewok_lake_vill','no_build_region',-650,-5076,100,100,3,1,2),
 (229,'endor_badge:maruaders_stronghold','no_build_region',-4628,-2273,100,100,3,1,2),
 (230,'lok_badge:imp_outpost','no_build_region',-1814,-3086,100,100,4,1,2),
 (231,'lok_badge:mount_chaolt','no_build_region',3091,-4638,100,100,4,1,2),
 (232,'lok_badge:kimo_skeleton','no_build_region',4562,-1156,100,100,4,1,2),
 (233,'naboo_badge:theed_waterfall','no_build_region',-4628,4207,100,100,5,1,2),
 (234,'naboo_badge:peak_waterfall','no_build_region',5157,-1646,100,100,5,1,2),
 (235,'naboo_badge:amidala_beach','no_build_region',-5828,-93,100,100,5,1,2),
 (236,'naboo_badge:gungan_place','no_build_region',-2066,-5423,100,100,5,1,2),
 (237,'rori_badge:hyperdrive_fac','no_build_region',-1130,4544,100,100,6,1,2),
 (238,'rori_badge:imp_camp','no_build_region',-5633,-5661,100,100,6,1,2),
 (239,'rori_badge:reb_outpost','no_build_region',3664,-6501,100,100,6,1,2),
 (240,'rori_badge:spice_mine','no_build_region',7371,169,100,100,6,1,2),
 (241,'talus_badge:durbin','no_build_region',4133,962,100,100,7,1,2),
 (242,'talus_badge:imp_outpost','no_build_region',-2184,2405,100,100,7,1,2),
 (243,'talus_badge:imp_reb_batle','no_build_region',-2452,3846,100,100,7,1,2),
 (244,'talus_badge:aquq_cave','no_build_region',-4425,-1414,100,100,7,1,2),
 (245,'tatooine_badge:lars_home','no_build_region',-2579,-5500,100,100,8,1,2),
 (246,'tatooine_badge:bens_hut','no_build_region',-4512,-2270,100,100,8,1,2),
 (247,'tatooine_badge:sarlacc','no_build_region',-6176,-3372,100,100,8,1,2),
 (248,'tatooine_badge:escape_pod','no_build_region',-3930,-4425,100,100,8,1,2),
 (249,'tatooine_badge:krayt_skull','no_build_region',-4650,-4363,100,100,8,1,2),
 (250,'tatooine_badge:krayt_graveyard','no_build_region',7428,4563,100,100,8,1,2),
 (251,'tatooine_badge:fort_tusken','no_build_region',-3969,6267,100,100,8,1,2),
 (252,'yavin_badge:exar_kun','no_build_region',5076,5537,100,100,9,1,2),
 (253,'yavin_badge:blueleaf_temple','no_build_region',-875,-2047,100,100,9,1,2),
 (254,'yavin_badge:woolamander_palace','no_build_region',519,-646,100,100,9,1,2),
 (255,'taanab_badge:taanab_starport','no_build_region',299,3742,100,100,42,1,2),
 (256,'Gungan monument','no_build_region',-7565,2265,0,100,5,1,4),
 (257,'Large Imperial Base (Faction)','no_build_region',-6500,-3265,0,400,5,1,4),
 (258,'Skewered Gungan','no_build_region',-6370,6500,0,60,5,1,4),
 (259,'Beach,Town','no_build_region',-5100,-100,0,100,5,1,4),
 (260,'Imperial Base','no_build_region',-5032,2782,0,400,5,1,4),
 (261,'Gungan statues','no_build_region',-3372,3834,0,60,5,1,4),
 (262,'Water Ruins','no_build_region',-3150,2600,0,60,5,1,4),
 (263,'Gungan Sacred Place - Boss Nass','no_build_region',-2000,-5400,0,400,5,1,4),
 (264,'Gungan Warrior Stronghold','no_build_region',-272,2878,0,400,5,1,4),
 (265,'Mordran (NPC)','no_build_region',-1952,-5279,0,60,5,1,4),
 (266,'Gungan statues','no_build_region',1999,2568,0,60,5,1,4),
 (267,'Emperor\'s Retreat','no_build_region',2400,-3900,0,600,5,1,4),
 (268,'Base','no_build_region',3000,5000,0,250,5,1,4),
 (269,'Ruins','no_build_region',3400,5000,0,100,5,1,4),
 (270,'Rebel Base','no_build_region',3600,5100,0,200,5,1,4),
 (271,'Rebel Base','no_build_region',4793,5582,0,200,5,1,4),
 (272,'Imperial vs. Gungan Battle','no_build_region',4825,-3820,0,400,5,1,4),
 (273,'Weapon Development Facility','no_build_region',-6456,-3235,0,300,5,1,4),
 (274,'Naboo Kidnapped Royalty','no_build_region',-1500,-1730,0,60,5,1,4),
 (275,'Mauler Stronghold','no_build_region',2963,1109,0,300,5,1,4),
 (276,'Veermok Cave','no_build_region',5702,-1544,0,150,5,1,4),
 (277,'Narglatch Cave','no_build_region',5838,-4666,0,150,5,1,4),
 (278,'Sarlacc Pit','no_build_region',-6183,-3371,0,200,8,1,4),
 (279,'crashed escape pod and gravestones','no_build_region',-6174,5888,0,60,8,1,4),
 (280,'Jawa Fortress','no_build_region',-6110,1892,0,300,8,1,4),
 (281,'The,Shrub','no_build_region',-5249,2551,0,200,8,1,4),
 (282,'Ben Kenobi\'s Hut','no_build_region',-4773,-3009,0,300,8,1,4),
 (283,'Krayt Skeleton','no_build_region',-4670,-4350,0,60,8,1,4),
 (284,'Krayt Skeleton','no_build_region',-4642,-1912,0,60,8,1,4),
 (285,'R2 3PO Escape Pod','no_build_region',-3933,-4417,0,60,8,1,4),
 (286,'Beggar\'s Canyon','no_build_region',-3880,-800,0,60,8,1,4),
 (287,'Hedge maze','no_build_region',-3039,-5104,0,200,8,1,4),
 (288,'Lars Homestead','no_build_region',-2600,-5500,0,300,8,1,4),
 (289,'Arnthout','no_build_region',-1470,3730,0,200,8,1,4),
 (290,'Small Camp','no_build_region',-1100,-3000,0,60,8,1,4),
 (291,'Darklighter Residence','no_build_region',-696,-6728,0,400,8,1,4),
 (292,'Hutt Hideout','no_build_region',5121,647,0,200,8,1,4),
 (293,'Squill Cavern','no_build_region',64,-81,0,300,8,1,4),
 (294,'Broken White Brigde','no_build_region',-4250,3630,0,60,0,1,4),
 (295,'Statue','no_build_region',-1905,3988,0,60,0,1,4),
 (296,'Crashed Pod half covered by sand','no_build_region',-1753,-3292,0,60,0,1,4),
 (297,'Droid Graveyard','no_build_region',-1642,-45,0,60,0,1,4),
 (298,'Serji-X Arrogantus (NPC)','no_build_region',-204,4577,0,60,0,1,4),
 (299,'Ignar Ominaz (NPC)','no_build_region',1806,4989,0,60,0,1,4),
 (300,'A wall in the middle of nowhere','no_build_region',2547,4744,0,60,0,1,4),
 (301,'A NPC Wind generator farm','no_build_region',6307,4376,0,150,0,1,4),
 (302,'Afarathu Cave','no_build_region',-2517,2922,0,150,0,1,4),
 (303,'Drall Cave','no_build_region',1031,4203,0,150,0,1,4),
 (304,'Nyax Cultists Outpost','no_build_region',1400,-300,0,400,0,1,4),
 (305,'Weapons Depot','no_build_region',-4899,-3137,0,400,7,1,4),
 (306,'Erran Sif (NPC)','no_build_region',2145,-5576,0,60,7,1,4),
 (307,'Small walled Island','no_build_region',2446,2474,0,100,7,1,4),
 (308,'Corsec vs. Flail Battle','no_build_region',2938,6004,0,350,7,1,4),
 (309,'Giant Decay Mite Cave','no_build_region',-5505,-4680,0,150,7,1,4),
 (310,'Khamurra Biogenetic Research Station','no_build_region',-4816,-4752,0,400,7,1,4),
 (311,'Giant Flynock Cave','no_build_region',1508,-858,0,150,7,1,4),
 (312,'Detainment Center','no_build_region',4963,-5977,0,400,7,1,4),
 (313,'Binyare Pirate Base','no_build_region',5526,-4073,0,200,7,1,4),
 (314,'Aakuan Champion\'s Cave','no_build_region',5939,4562,0,150,7,1,4),
 (315,'Research Base','no_build_region',-1120,4480,0,300,6,1,4),
 (316,'Rori Gungan Swamp Town','no_build_region',-1986,3339,0,400,6,1,4),
 (317,'Poacher vs. Creature Battle','no_build_region',773,-2109,0,400,6,1,4),
 (318,'Garyn Raiders Bunker','no_build_region',-6004,-1851,0,150,6,1,4),
 (319,'Pygmy Tortons Cave','no_build_region',-1814,-4533,0,150,6,1,4),
 (320,'Borgle Bat Cave','no_build_region',902,-4933,0,150,6,1,4),
 (321,'Giant Bark Mite Cave','no_build_region',3584,5419,0,150,6,1,4),
 (322,'Cobral Hideout','no_build_region',5464,5045,0,300,6,1,4),
 (323,'Canyon Corsair Hideout','no_build_region',-3792,-3904,0,500,4,1,4),
 (324,'Gurk Kings Lair','no_build_region',-3762,-3467,0,150,4,1,4),
 (325,'Kimogola Town','no_build_region',-176,2856,0,300,4,1,4),
 (326,'Monolith','no_build_region',3456,-399,0,100,4,1,4),
 (327,'Giant Maze','no_build_region',3824,-465,0,100,4,1,4),
 (328,'Droid Dungeon','no_build_region',3314,-4902,0,150,4,1,4),
 (329,'Ewok Village','no_build_region',50,50,0,300,3,1,4),
 (330,'An empty lake village','no_build_region',1500,-3300,0,300,3,1,4),
 (331,'Orphaned Marauder\'s Cave','no_build_region',-6853,679,0,150,3,1,4),
 (332,'Death Watch Bunker','no_build_region',-4680,4330,0,300,3,1,4),
 (333,'Jinda Ritualist\'s Cave','no_build_region',-1695,-56,0,150,3,1,4),
 (334,'Korga Caves','no_build_region',2286,3459,0,150,3,1,4),
 (335,'stones','no_build_region',-7236,4324,0,60,1,1,4),
 (336,'Mokk Stronghold','no_build_region',-7258,-3320,0,200,1,1,4),
 (337,'Large native villages','no_build_region',-7212,-806,0,200,1,1,4),
 (338,'Native huts','no_build_region',-7085,-6149,0,100,1,1,4),
 (339,'Large head','no_build_region',-6952,5614,0,60,1,1,4),
 (340,'Huge abandoned Rebel base that Princess Leia mentions','no_build_region',-6947,5614,0,500,1,1,4),
 (341,'Native huts','no_build_region',-6196,2670,0,100,1,1,4),
 (342,'stone arches','no_build_region',-6143,4675,0,60,1,1,4),
 (343,'Native huts','no_build_region',-6028,1123,0,100,1,1,4),
 (344,'Native huts','no_build_region',-5784,3421,0,100,1,1,4),
 (345,'Two carved heads facing each other across a small gorge','no_build_region',-5549,4507,0,60,1,1,4),
 (346,'Somewhat buried disk with two large logs on either side','no_build_region',-5389,1387,0,60,1,1,4),
 (347,'Carved head with 3 Jedi era columns around it','no_build_region',-4974,6386,0,60,1,1,4),
 (348,'Circle of sharp pointed stones','no_build_region',-4553,2728,0,100,1,1,4),
 (349,'Jedi era building on top of a hill','no_build_region',-4495,1636,0,100,1,1,4),
 (350,'Native huts','no_build_region',-4436,5295,0,100,1,1,4),
 (351,'Columns leading up to an arch way (Jedi era)','no_build_region',-4217,4235,0,100,1,1,4),
 (352,'Large native village','no_build_region',-3841,-5749,0,100,1,1,4),
 (353,'3 carved heads and 2 totems on hill','no_build_region',-3648,3971,0,100,1,1,4),
 (354,'Step pyramid with carved head on top','no_build_region',-3409,2913,0,150,1,1,4),
 (355,'Jedi area causeway across a lake','no_build_region',-3127,3394,0,200,1,1,4),
 (356,'Small hill with spiked stone outcroppings','no_build_region',-2480,4599,0,100,1,1,4),
 (357,'Ruined building','no_build_region',-2421,3370,0,200,1,1,4),
 (358,'Native huts','no_build_region',-2015,1432,0,100,1,1,4),
 (359,'Adobe hut with large metal pipe out the top','no_build_region',-2004,1243,0,100,1,1,4),
 (360,'Animal heads stacked on top of one another with one totem','no_build_region',-1818,3794,0,100,1,1,4),
 (361,'Tent (Native)','no_build_region',-1587,5486,0,100,1,1,4),
 (362,'Ruined stone building','no_build_region',-1473,2669,0,200,1,1,4),
 (363,'Large head buried in the side of hill overlooking a lake','no_build_region',-1189,4156,0,60,1,1,4),
 (364,'A step pyramid','no_build_region',-897,6883,0,150,1,1,4),
 (365,'Jedi era building and arch on Island near the mining camp','no_build_region',-781,2087,0,150,1,1,4),
 (366,'3 totems forming a triangle (with a tree in the middle)','no_build_region',-712,1463,0,60,1,1,4),
 (367,'Stone head about to fall in to a lake','no_build_region',-478,2075,0,60,1,1,4),
 (368,'Two carved heads with one laying down','no_build_region',-292,6883,0,60,1,1,4),
 (369,'Fenced in pond with totem and animal skeleton','no_build_region',-202,5955,0,60,1,1,4),
 (370,'Buried step pyramid with alter still exposed','no_build_region',130,5242,0,60,1,1,4),
 (371,'Set of columns across river','no_build_region',237,2171,0,60,1,1,4),
 (372,'Stone','no_build_region',338,5543,0,60,1,1,4),
 (373,'Jedi era ruins','no_build_region',446,4646,0,60,1,1,4),
 (374,'Rock outcropping','no_build_region',563,1873,0,60,1,1,4),
 (375,'Buried Jedi era arch','no_build_region',897,1393,0,60,1,1,4),
 (376,'Jedi era arch','no_build_region',1158,5752,0,60,1,1,4),
 (377,'Native huts','no_build_region',1586,5959,0,60,1,1,4),
 (378,'Native huts','no_build_region',1927,1467,0,60,1,1,4),
 (379,'Jedi era circle of ruined columns','no_build_region',2077,5334,0,60,1,1,4),
 (380,'3 carved heads along lake','no_build_region',2317,6196,0,60,1,1,4),
 (381,'Adobe style arch with flames coming out the top','no_build_region',2885,4482,0,60,1,1,4),
 (382,'3 carved heads on a small island all facing outward','no_build_region',3087,1217,0,60,1,1,4),
 (383,'Native hut with 2 totems and a fenced in coral','no_build_region',3181,5967,0,60,1,1,4),
 (384,'Jedi Temple and Academy','no_build_region',4154,5254,0,350,1,1,4),
 (385,'Stone','no_build_region',4630,3643,0,60,1,1,4),
 (386,'2 native huts in semi wooded area','no_build_region',4873,4508,0,60,1,1,4),
 (387,'Ruined building','no_build_region',5019,6841,0,250,1,1,4),
 (388,'Wood bridge and fence','no_build_region',5270,-4573,0,100,1,1,4),
 (389,'Four stone arches that form a box','no_build_region',5900,-16,0,60,1,1,4),
 (390,'Force Crystal Hunters Cave','no_build_region',-6259,7336,0,150,1,1,4),
 (391,'The Warren','no_build_region',-580,-3763,0,200,1,1,4),
 (392,'Kunga Stronghold','no_build_region',-368,-240,0,150,1,1,4),
 (393,'Junta Stronghold','no_build_region',6994,-4110,0,150,1,1,4),
 (394,'Small force protected monument','no_build_region',-5019,3207,0,200,2,1,4),
 (395,'Night Sister vs Mountain Clan battlefield','no_build_region',-2599,1530,0,400,2,1,4),
 (396,'Singing Mountain Sister Clan Dungeon','no_build_region',156,4521,0,300,2,1,4),
 (397,'Singing Mountain Clan Deserted Village #1','no_build_region',561,4241,0,400,2,1,4),
 (398,'Spider Cave','no_build_region',-6474,888,0,300,2,1,4),
 (399,'Night Sister Dungeon','no_build_region',-3991,-57,0,300,2,1,4),
 (400,'NS cave (Spider Clan)','no_build_region',-1165,6300,0,300,2,1,4),
 (401,'Singing Mountain Clan Dungeon','no_build_region',158,4524,0,300,2,1,4),
 (402,'Massassi Sacrificial Stone','no_build_region',-7550,-440,0,100,9,1,4),
 (403,'Massassi Ruins','no_build_region',-6490,7350,0,100,9,1,4),
 (404,'Massassi Pyramid','no_build_region',-6350,-670,0,100,9,1,4),
 (405,'Massassi Statue','no_build_region',-4750,4960,0,60,9,1,4),
 (406,'A statue of some sort','no_build_region',-4689,-5420,0,60,9,1,4),
 (407,'Death Star Turret','no_build_region',-4150,5330,0,200,9,1,4),
 (408,'Imperial Temple','no_build_region',-3100,-3030,0,300,9,1,4),
 (409,'Kliknik Temple','no_build_region',-900,-2020,0,600,9,1,4),
 (410,'Massassi Pyramid Ruins','no_build_region',300,-4440,0,500,9,1,4),
 (411,'Burning Tree','no_build_region',320,-5300,0,100,9,1,4),
 (412,'Death Star Turret Barrel','no_build_region',320,-3140,0,60,9,1,4),
 (413,'Temple of the Woolamander','no_build_region',480,-620,0,500,9,1,4),
 (414,'Massassi Ruins','no_build_region',910,3560,0,500,9,1,4),
 (415,'Massassi Statue','no_build_region',940,4450,0,60,9,1,4),
 (416,'Gazebo','no_build_region',950,-1450,0,60,9,1,4),
 (417,'Stone faces','no_build_region',1980,-5310,0,60,9,1,4),
 (418,'Large stone face','no_build_region',4010,-2850,0,60,9,1,4),
 (419,'Crater','no_build_region',5900,-4320,0,200,9,1,4),
 (420,'More deathstar wreckage','no_build_region',7220,-1400,0,60,9,1,4),
 (421,'Cave','no_build_region',-1600,-800,0,300,9,1,4),
 (422,'Geonosian Lab','no_build_region',-6450,-360,0,300,9,1,4),
 (423,'Jedi Shrine','no_build_region',-7391,-3938,0,500,0,1,4),
 (424,'Jedi Shrine','no_build_region',6300,6687,0,500,0,1,4),
 (425,'Jedi Shrine','no_build_region',-2384,6393,0,500,0,1,4),
 (426,'Jedi Shrine','no_build_region',-6907,4527,0,500,0,1,4),
 (427,'Jedi Shrine','no_build_region',6092,4527,0,500,0,1,4),
 (428,'Jedi Shrine','no_build_region',-1814,-6202,0,500,1,1,4),
 (429,'Jedi Shrine','no_build_region',-6999,-5269,0,500,1,1,4),
 (430,'Jedi Shrine','no_build_region',2640,-1536,0,500,1,1,4),
 (431,'Jedi Shrine','no_build_region',-6173,4120,0,500,1,1,4),
 (432,'Jedi Shrine','no_build_region',2163,7548,0,500,1,1,4),
 (433,'Jedi Shrine','no_build_region',3087,4887,0,500,2,1,4),
 (434,'Jedi Shrine','no_build_region',1654,-5765,0,500,2,1,4),
 (435,'Jedi Shrine','no_build_region',-4961,-3493,0,500,2,1,4),
 (436,'Jedi Shrine','no_build_region',-4148,5926,0,500,2,1,4),
 (437,'Jedi Shrine','no_build_region',5570,-1514,0,500,2,1,4),
 (438,'Jedi Shrine','no_build_region',670,5548,0,500,3,1,4),
 (439,'Jedi Shrine','no_build_region',-5055,-1703,0,500,3,1,4),
 (440,'Jedi Shrine','no_build_region',-5627,4813,0,500,3,1,4),
 (441,'Jedi Shrine','no_build_region',5116,1923,0,500,3,1,4),
 (442,'Jedi Shrine','no_build_region',-3870,-4467,0,500,3,1,4),
 (443,'Jedi Shrine','no_build_region',-2132,5938,0,500,4,1,4),
 (444,'Jedi Shrine','no_build_region',5455,3805,0,500,4,1,4),
 (445,'Jedi Shrine','no_build_region',-5806,1977,0,500,4,1,4),
 (446,'Jedi Shrine','no_build_region',4978,-5674,0,500,4,1,4),
 (447,'Jedi Shrine','no_build_region',-3641,-6030,0,500,4,1,4),
 (448,'Jedi Shrine','no_build_region',2377,-473,0,500,5,1,4),
 (449,'Jedi Shrine','no_build_region',7182,-234,0,500,5,1,4),
 (450,'Jedi Shrine','no_build_region',-6859,-1937,0,500,5,1,4),
 (451,'Jedi Shrine','no_build_region',-2583,-6184,0,500,5,1,4),
 (452,'Jedi Shrine','no_build_region',-4496,-7531,0,500,6,1,4),
 (453,'Jedi Shrine','no_build_region',307,-978,0,500,6,1,4),
 (454,'Jedi Shrine','no_build_region',6854,-1221,0,500,6,1,4),
 (455,'Jedi Shrine','no_build_region',-926,6046,0,500,6,1,4),
 (456,'Jedi Shrine','no_build_region',-6375,6403,0,500,6,1,4),
 (457,'Jedi Shrine','no_build_region',-5785,4478,0,500,7,1,4),
 (458,'Jedi Shrine','no_build_region',318,5842,0,500,7,1,4),
 (459,'Jedi Shrine','no_build_region',-5494,-3241,0,500,7,1,4),
 (460,'Jedi Shrine','no_build_region',5760,-5208,0,500,7,1,4),
 (461,'Jedi Shrine','no_build_region',5958,-5685,0,500,8,1,4),
 (462,'Jedi Shrine','no_build_region',-3622,5280,0,500,8,1,4),
 (463,'Jedi Shrine','no_build_region',5264,113,0,500,8,1,4),
 (464,'Jedi Shrine','no_build_region',-6505,-3667,0,500,8,1,4),
 (465,'Jedi Shrine','no_build_region',5632,6015,0,500,8,1,4),
 (466,'Jedi Shrine','no_build_region',2389,-4934,0,500,9,1,4),
 (467,'Jedi Shrine','no_build_region',-4585,-3761,0,500,9,1,4),
 (468,'Jedi Shrine','no_build_region',-3362,6914,0,500,9,1,4),
 (469,'Jedi Shrine','no_build_region',6455,6423,0,500,9,1,4);
/*!40000 ALTER TABLE `planet_regions` ENABLE KEYS */;




/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
