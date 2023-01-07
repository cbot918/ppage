describe 'database' do
    def run_script(commands)
        raw_output = nil
        IO.popen("./ydb-go.exe", "r+") do |pipe|
            commands.each do |command|
                pipe.puts command
            end

            pipe.close_write

            raw_output = pipe.gets(nil)
        end
        raw_output.split("\n")
    end

    it 'parse statement failed' do
        result = run_script(["insert a"])
        expect(result).to match_array([
            "db > Syntax error. Could not parse statement.",
            "db > "])
        # puts "hi"
    end

    it 'parse statement failed2' do
        result = run_script(["ins"])
        expect(result).to match_array([
            "db > Unrecognized keyword at start of: ins",
            "db > "])
        # puts "hi"
    end

end