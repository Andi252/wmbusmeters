#!/bin/sh

PROG="$1"

mkdir -p testoutput

TEST=testoutput

####################################################
TESTNAME="Test duplicates are ignored"
TESTRESULT="ERROR"

cat > $TEST/test_expected_unsorted.txt <<EOF
{"_":"telegram","media":"smoke detector","meter":"lansensm","name":"Rummet","id":"01000273","status":"OK","async_msg_id_counter":588,"minutes_since_last_manual_test_counter":30022,"timestamp":"1111-11-11T11:11:11Z"}
EOF

jq --sort-keys . $TEST/test_expected_unsorted.txt > $TEST/test_expected.txt

$PROG --format=json --ignoreduplicates simulations/simulation_duplicates.txt \
          Rummet lansensm 01000273 "" \
    | grep Rummet | jq --sort-keys . > $TEST/test_output.txt

if [ "$?" = "0" ]
then
    cat $TEST/test_output.txt | sed 's/"timestamp": "....-..-..T..:..:..Z"/"timestamp": "1111-11-11T11:11:11Z"/' > $TEST/test_responses.txt
    diff $TEST/test_expected.txt $TEST/test_responses.txt
    if [ "$?" = "0" ]
    then
        echo "OK: $TESTNAME"
        TESTRESULT="OK"
    else
        if [ "$USE_MELD" = "true" ]
        then
            meld $TEST/test_expected.txt $TEST/test_responses.txt
        fi
    fi
fi

if [ "$TESTRESULT" = "ERROR" ]; then echo ERROR: $TESTNAME;  exit 1; fi

####################################################
TESTNAME="Test duplicates are left alone"
TESTRESULT="ERROR"

cat > $TEST/test_expected_unsorted.txt <<EOF
{"_":"telegram","media":"smoke detector","meter":"lansensm","name":"Rummet","id":"01000273","status":"OK","async_msg_id_counter":588,"minutes_since_last_manual_test_counter":30022,"timestamp":"1111-11-11T11:11:11Z"}
{"_":"telegram","media":"smoke detector","meter":"lansensm","name":"Rummet","id":"01000273","status":"OK","async_msg_id_counter":588,"minutes_since_last_manual_test_counter":30022,"timestamp":"1111-11-11T11:11:11Z"}
{"_":"telegram","media":"smoke detector","meter":"lansensm","name":"Rummet","id":"01000273","status":"OK","async_msg_id_counter":588,"minutes_since_last_manual_test_counter":30022,"timestamp":"1111-11-11T11:11:11Z"}
{"_":"telegram","media":"smoke detector","meter":"lansensm","name":"Rummet","id":"01000273","status":"OK","async_msg_id_counter":588,"minutes_since_last_manual_test_counter":30022,"timestamp":"1111-11-11T11:11:11Z"}
{"_":"telegram","media":"smoke detector","meter":"lansensm","name":"Rummet","id":"01000273","status":"OK","async_msg_id_counter":588,"minutes_since_last_manual_test_counter":30022,"timestamp":"1111-11-11T11:11:11Z"}
EOF

jq --sort-keys .  $TEST/test_expected_unsorted.txt > $TEST/test_expected.txt

$PROG --format=json --ignoreduplicates=false simulations/simulation_duplicates.txt \
          Rummet lansensm 01000273 "" \
    | grep Rummet | jq --sort-keys . > $TEST/test_output.txt

if [ "$?" = "0" ]
then
    cat $TEST/test_output.txt | sed 's/"timestamp": "....-..-..T..:..:..Z"/"timestamp": "1111-11-11T11:11:11Z"/' > $TEST/test_responses.txt
    diff $TEST/test_expected.txt $TEST/test_responses.txt
    if [ "$?" = "0" ]
    then
        echo "OK: $TESTNAME"
        TESTRESULT="OK"
    else
        if [ "$USE_MELD" = "true" ]
        then
            meld $TEST/test_expected.txt $TEST/test_responses.txt
        fi
    fi
fi

if [ "$TESTRESULT" = "ERROR" ]; then echo ERROR: $TESTNAME;  exit 1; fi
