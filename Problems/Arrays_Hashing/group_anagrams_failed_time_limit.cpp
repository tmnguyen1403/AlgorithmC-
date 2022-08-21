#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <ctime>
#include <chrono>
class Solution {
public:
    using anagram_map = std::map<char, int>;

    anagram_map createMap(std::string str) {
        anagram_map result;
        for (const auto& c: str) {
            if (result.find(c) == result.end()) {
                result.insert(std::pair<char, int>(c, 0));
            }
            result[c] += 1;
        }
        return result;
    }

    bool isAnagram(anagram_map firstMap, anagram_map secondMap ) {
        if (firstMap.size() != secondMap.size()) {
            return false;
        }
        for (const auto& [key, occurence] : firstMap) {
            auto it2 = secondMap.find(key);
            if (it2 == secondMap.end() || it2->second != occurence) {
                return false;
            }
        }
        return true;
    }

    void group_by(std::vector<std::string>& strs, 
        const std::map<std::string,anagram_map>& str_maps, 
        std::vector<std::vector<std::string>> &group_vector  ) {
        
        for (const auto& str: strs) {
            std::cout << str << std::endl;
        }
        if (strs.empty()) {
            return;
        }
        std::vector<std::string> group;
        std::string firstStr = strs[0];
        auto strIt = strs.begin();
        while (strIt != strs.end()) {
            auto map1It = str_maps.find(firstStr);
            auto map2It = str_maps.find(*strIt);
            if (map1It == str_maps.end() || map2It == str_maps.end()) {
                continue;
            }
            if ( isAnagram(map1It->second, map2It->second) ) {
                group.push_back(*strIt);
                strIt = strs.erase(strIt);
            } else {
                strIt++;
            }
        }
        group_vector.push_back(group);
        group_by(strs, str_maps, group_vector);
    }

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> group_vector;

        if (strs.size() == 0) {
            return group_vector;
        }

        std::map<std::string,anagram_map> str_maps;

        for (const auto& str: strs) {
            if (str_maps.find(str) == str_maps.end()) {
                str_maps.insert(
                    std::pair<std::string, anagram_map>(str,createMap(str)));
            }
        }
        
        group_by(strs, str_maps, group_vector);
        return group_vector;
    }
};

int main() {

    std::vector<std::string> strs {"eat","tea","tan","ate","nat","bat"};
    
    Solution solver;
    auto group_result = solver.groupAnagrams(strs);

    int group_counter = 0;
    for (const auto& group: group_result) {
        group_counter++;
        std::cout << "group " << group_counter << ": " << std::endl;
        for (const auto& str: group) {
            std::cout << str << std::endl;
        }
    }

    std::vector<std::string> strs2 {"bluffed","excellently","neurology","nonrefillable","edmund","boyhoods","survivors","sexually","outnumbering","bolero","werewolf","debasing","dragnet","addams","monochromes","flippancy","hoots","digestion","profanity","cellist","enrols","crumble","elderberry","jayson","recopying","threats","exploded","cinnamon","hospitalized","ducat","memorialize","powerlessly","suaver","deservings","genuinely","calliope","oxidize","gamekeeper","slimming","daises","resisted","shanty","receivable","careering","transmigration","dooms","revisiting","financed","severs","hominy","pantomiming","bestride","seam","alibi","churchman","ovule","jaxartes","retirement","translated","pancaking","achiever","navigates","hazes","tubman","versatility","fergus","adjust","narcosis","hightail","mormon","hattie","chinning","teenager","tho","misbehaves","trustfulness","electioneers","emending","disenchanting","barometer","styluses","uruguay","houseboat","rungs","endwise","reinterpretation","gashes","koshers","nostalgic","hateful","bray","sutures","saudis","sentimentalizes","ayers","avoided","spiky","circumnavigated","tonic","dialects","disbursing","manitoba","potbellies","cauldron","whitened","fitter","attorney","doorbell","scrolled","noncontagious","overnight","rubbishes","stove","amortizing","periling","doublet","celina","whitfield","tonsures","overturns","missions","casuals","juxtaposing","sings","hesperus","panhandle","armando","bernays","trimmers","transom","grafts","columns","abelson","archway","infantries","orly","pock","selectors","lecterns","humps","kinked","bridles","essentials","instead","eliminating","mabel","zing","impersonation","cudgels","chang","artifacts","creon","clucking","skedaddled","spryer","footballs","honeys","wafer","knelt","flagstone","americanize","bohr","plottered","simone","conventional","definable","blackbirds","woodsier","carriage","residents","mezzanines","tenement","plymouth","wresting","islanders","malleable","attentively","irrelevancy","paulette","hillbillies","leech","cloaks","individualist","uncannier","patel","effusions","dungs","plugs","discompose","dacrons","teletypes","dismay","germany","travailing","loathes","devouter","chandelier","rinsed","denial","mil","outmanoeuvre","tugged","icings","reefer","dominicans","franz","destruct","bog","pinhole","jackknife","polytheists","chatted","tomfoolery","breeziness","beaked","tasman","possession","partying","shift","anodynes","pontificate","typefaces","mullions","reconnaissance","stanching","bedstead","belligerent","breakwaters","messerschmidt","instincts","sickle","quondam","limos","fosters","mentalities","minestrone","harrowed","folsom","travesty","compendiums","maladies","narrates","interlocks","humbleness","uplifted","slipknot","motorcyclists","restarted","iconoclast","forts","trumpery","cute","harpsichord","klutzier","ashtray","garlicking","sprayer","duodenal","parboiled","ultras","arkansan","metaphor","patterning","lorries","donetsk","coerced","constricted","murkiness","curtailing","bookish","tenacious","araucanian","unmask","forlorner","ills","bert","closures","cahoots","rotundity","sullying","pare","pretences","beggar","childproofs","educable","duct","posits","bushed","southward","echelon","approximates","spoonerism","waitresses","unman","isolation","suleiman","delight","skimping","rambles","redistrict","alderwomen","o","rejoiced","blot","backpedals","clearings","brontosauruses","laughingly","huckleberries","steinbeck","friskier","commander","skivvies","reality","intermingles","cumbersome","bribery","disagreeable","jersey","lamont","profiteered","shooters","transience","scraper","resignedly","grabbing","christies","piaget","executors","reproachfully","spasming","overproduction","incises","priesthoods","straightforwards","poesied","welled","bickered","drolleries","manures","daffy","segregate","waddles","cheerfully","overprinted","molester","lief","summarizes","vaccination","seminole","unlisted","rumping","ed","weir","manufacture","secretariat","fulminated","molybdenum","bakersfield","unpinning","heroism","violence","mistimed","alcoa","perter","manuscripts","separate","retractions","safes","atoll","grottos","boogieing","olga","frisking","grows","redeployment","helmholtz","durant","rankest","thespian","cheese","pilaf","thinness","contrast","parqueted","milkmaids","blackhead","breathlessly","bothering","decoration","arrogant","setups","contraptions","swirly","transgression","misses","handyman","snows","clinic","vatican","forecaster","haughtiness","bovine","strobe","ingram","maratha","descartes","billeting","treetop","aloud","globed","monument","argumentative","squeegee","especial","retrofits","artistes","propose","piraeus","horsetails","tailpipes","throughout","tarted","synods","unconcerned","weighting","duding","roe","undervalued","reachable","thicker","egging","dentistry","byte","distinguished","envisioning","filibusters","housewarming","matzot","dill","remarries","anatomical","kremlinologists","truancy","bostonians","limited","poorer","corniest","contradictory","three","temporaries","convivial","shirting","schisms","balconies","reinterpret","suturing","kumquats","oncology","unbidden","correlates","kowtows","flashest","neighborhood","rumbas","swathed","webb","birches","engages","promoters","outside","cheeriest","suffusion","propounding","bagels","amish","contrarily","xylophonists","familiarize","makes","testimony","crusaded","wildcatted","slackest","bovines","artier","plops","robbie","slosh","dinkier","airworthiest","carbohydrates","teammates","locoweed","stratagems","sarcoma","gougers","yuletide","rosemarie","upholster","sizzle","reminiscing","bluffers","shellac","heckled","hypothalami","showery","supposes","humbug","burnished","lopsided","imprisons","opine","leeches","generic","stimulated","soggily","aftershave","marvell","pekoe","microorganism","burlap","topples","misfire","scuttlebutt","tantrums","exits","eclecticism","alden","ilk","deltas","slack","effortlessly","operationally","offspring","staggers","alkalis","logger","spines","oscilloscope","tiniest","fluxed","collectively","leagues","procter","protruding","flukiest","underemployed","wetter","ignite","puddings","magnetosphere","solids","oceangoing","barrooms","refurnished","operational","mastering","white","organist","blackest","licentiates","marsupial","machinists","borderlands","dingies","kegging","dualism","cohen","existing","wheeler","uncleanly","umlauts","expiate","misspends","ebert","camber","adventured","weave","bounded","religiously","potluck","scions","millionths","goblet","witchery","dodge","sarasota","pier","membranous","stomaching","tallyhos","cohort","leveraged","makeshift","hexagon","thumped","zedong","versions","ultraconservatives","obeyed","pace","wicks","luncheoning","minerals","medications","moralizes","unites","rant","portents","apparelling","hums","farrowed","verve","boggiest","weal","josephus","perfects","beef","stairwell","comment","arrant","stature","kc","quoits","galls","adoption","reformulate","physicals","schroeder","scoundrels","delivered","crushed","rue","thrives","cerf","hijacker","inkier","vulvae","deterring","burgles","catechism","unhorse","reclined","dapple","angioplasties","sluggards","emceed","snobbery","accessory","cardiologist","browning","crosses","boasted","summonsing","gamble","overdue","scourge","dirges","cascades","precious","peacefuller","oysters","hoods","pirates","sauerkraut","whiskers","defames","repute","foolish","lactate","tharp","electrocutions","fating","freezers","invocation","dissenter","should","hells","homesickness","archdukes","preconceiving","scroungers","embellishment","massacre","upon","aerated","protuberant","sternly","meticulously","virulent","loch","enchant","raindrop","atrophies","magyar","interring","coachmen","exorcism","faintness","pointlessness","kawabata","installment","maliciously","vindicating","monkeying","uncanny","tangibles","blessed","forensic","arty","toppled","dilapidation","klutzes","moots","cottage","seismograph","diarists","aperitif","facing","filial","soundings","salsa","clear","cayenne","stilling","thighs","contrasting","cloistered","custodial","woodland","frillier","unrolls","landsat","chartres","toughly","saluted","verbose","transfiguring","zapped","iconoclasts","parkman","charlestons","spadework","okaying","numismatics","chestnuts","ghostwriters","nobelists","insouciant","vivisection","moods","edifices","relocated","wisdom","ignobly","namesakes","tapestry","schismatics","agra","blundering","sailboards","fruited","anticlimax","viewed","locus","barricading","rehearsed","irater","sibyl","steps","airsickness","blasphemous","swelling","salinger","veal","normalizes","gullet","inhabitant","slut","zinced","homing","headphone","chatters","winged","wingspread","kneecaps","tam","withdraws","repatriating","peter","isobars","dix","rekindled","snider","depends","mute","knowledgeably","mends","tides","stoutness","hempen","victoria","slaloming","buttons","grammars","astounding","memorandum","kenmore","solid","bandoliers","flowered","equivocation","assuredly","festers","helios","lebanese","impugned","shiftlessness","statement","announcer","vagueness","punctures","colonnade","exist","displeasing","diocletian","untold","unprintable","hereford","sidereal","joke","automatically","rendezvousing","surfed","surreptitious","depopulating","arching","massive","excise","beatles","rigorous","turnovers","impromptus","jezebels","glinted","leveraging","capsizing","voices","hitchhiking","ramon","wyeth","larva","unblushing","inanest","vacillate","contrives","kw","carboniferous","disinterred","predicated","song","andean","youths","previous","yours","supplicates","gompers","apprenticed","half","lactic","authenticating","charlatan","mendacious","flanks","hieronymus","dressy","owns","vestry","strobes","clapping","informers","sermoning","rifer","headstone","bobbing","forgiven","hypocritical","legation","adjusted","glibness","peeled","actuators","composition","payloads","abdication","delete","unnecessary","misprint","wooziest","cannibalistic","voiced","marooned","einstein","erratically","obsessions","impracticality","hoffa","rheumatics","handsets","tricked","afield","abdul","sounding","tray","massacring","iowan","grits","billy","purchases","profitably","resilience","eyed","vocabularies","golden","barking","riviera","helmsmen","cavorting","shrinks","hangmen","heliports","salve","assorting","neuroses","contribute","triathlon","adherents","gismo","sering","pulsate","hoarders","vacating","pulverization","destabilize","wore","eureka","gobs","raiding","valhalla","aureole","illustration","null","ageing","umbrellaing","characterize","ethel","bagging","lucas","nakedly","rinded","wainscottings","through","falter","clearness","smart","overspecializes","older","entourage","dawn"};

    auto start = std::chrono::high_resolution_clock::now();
    group_result = solver.groupAnagrams(strs2);
     auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "execution time in microseconds: " << duration.count() << std::endl;
    group_counter = 0;
    for (const auto& group: group_result) {
        group_counter++;
        std::cout << "group " << group_counter << ": " << std::endl;
        for (const auto& str: group) {
            std::cout << str << std::endl;
        }
    }
   

    return 0;
}